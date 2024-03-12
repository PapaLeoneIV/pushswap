#!/bin/bash

# Percorso degli eseguibili
push_swap_executable="./push_swap"
checker_executable="./checker_linux"

# Funzione per eseguire un singolo test
run_test() {
    input_numbers="$@"

    # Esegui il programma push_swap con gli argomenti passati e redirigi l'output su /dev/null
    push_swap_output=$($push_swap_executable $input_numbers 2> /dev/null)
    # Passa l'output di push_swap al programma checker tramite pipe e passa gli stessi argomenti, redirigendo anche l'output di checker su /dev/null
    checker_output=$(echo "$push_swap_output" | $checker_executable $input_numbers 2> /dev/null)

    # Controlla se sia l'output di push_swap che di checker sono "Error"
    push_swap_stderr=$($push_swap_executable $input_numbers  2>&1 )
    checker_stderr=$(echo "$push_swap_output" | $checker_executable $input_numbers  2>&1)

    if [ "$push_swap_stderr" = "Error" ] && [ "$checker_stderr" = "Error" ]; then
        echo "⛔🤡 Test non valido: [$input_numbers] gli input inseriti non sono validi, si è verificato un errore."
    elif [ "$checker_output" = "OK" ]; then
        echo "✅🤟 Test Passato:  [$input_numbers] è stato ordinato correttamente."
    elif [ -z "$push_swap_output" ] && [ -z "$checker_output" ]; then
        echo "✅🤟 Test Superato: [$input_numbers] i numeri sono già ordinati."
    else 
        echo "⛔🤡 Test Fallito: [$input_numbers] non è stato ordinato correttamente."
        echo "Output del checker: $checker_output"
    fi
}

valgrind_test() {
    input_numbers="$@"
    # Create unique filenames for Valgrind output
    push_swap_valgrind_output_file=$(mktemp)
    checker_valgrind_output_file=$(mktemp)

    # Execute push_swap with the arguments under Valgrind's supervision
    push_swap_output=$($push_swap_executable $input_numbers 2> /dev/null)
    valgrind --leak-check=full --error-exitcode=1 --log-file="$push_swap_valgrind_output_file" $push_swap_executable $input_numbers > /dev/null 2>&1

    # Check if there are memory leaks in push_swap
    if grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$push_swap_valgrind_output_file"; then
        echo "✅🤟 Valgrind test passato su push_swap:  [$input_numbers] non ci sono memory leaks."
    else
        echo "⛔🤡 Valgrind test fallito su push_swap: [$input_numbers] ci sono memory leaks."
        echo "Output di Valgrind su push_swap:"
        cat "$push_swap_valgrind_output_file"
        rm "$push_swap_valgrind_output_file" "$checker_valgrind_output_file"
        return
    fi

    # Execute the checker with the arguments under Valgrind's supervision
    echo "$push_swap_output" | valgrind --leak-check=full --error-exitcode=1 --log-file="$checker_valgrind_output_file" $checker_executable $input_numbers > /dev/null 2>&1
    allocs=$(grep "allocs" "$checker_valgrind_output_file" | awk '{print $5}')
    frees=$(grep "frees" "$checker_valgrind_output_file" | awk '{print $7}')

    # Calculate the difference between the number of allocations and deallocations
    diff=$((allocs - frees))

    # Check if there are memory leaks
    if [ $diff -eq 0 ]; then
        echo "✅🤟 Test Passato con Valgrind:  [$input_numbers] non ci sono memory leaks."
    else
        echo "⛔🤡 Test Fallito con Valgrind: [$input_numbers] ci sono memory leaks."
        echo "Output di Valgrind:"
        cat "$checker_valgrind_output_file"
    fi

    # Clean up temporary files
    rm "$push_swap_valgrind_output_file" "$checker_valgrind_output_file"
}


# Definire array con i casi limiti
special_cases=(
    ""         # Test con stringa vuota
    "a + 1"    # Test con carattere non numerico
    "--4 +4"   # Test con operatore non supportato
    "+0 -0"    # Test con zero non supportato
    "a + a"
    "1 2 3a"
    "\200 201"
    "1 1 3 4 5"
)

# Numero di test da eseguire 
num_tests=2

# Contatore dei test
test_count=0
# Esegui i test
while [ "$test_count" -lt "$num_tests" ]; do
    # Numero di numeri casuali per questo test
    echo "Numero di numeri casuali per il test $((test_count+1)): "
    read num_numbers

    # Genera una lista di numeri casuali tra 1 e 500 usando shuf e passala a run_test
    random_numbers=$(shuf -i 1-500 -n "$num_numbers")
    echo "Test $((test_count+1)):"
    run_test $random_numbers
    echo ""
    valgrind_test $random_numbers
    echo ""

    # Incrementa il contatore dei test
    test_count=$((test_count+1))
done

# Esegui i test speciali
echo "Test con input particolari:"
test_number=0
for case in "${special_cases[@]}"; do
    ((test_number++))
    echo "Test $test_number:"
    run_test "$case"
    valgrind_test "$case"
done





echo "Testing completato."
