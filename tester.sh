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

    # Esegui il push_swap con gli argomenti passati sotto la supervisione di Valgrind
    push_swap_output=$(valgrind --leak-check=full --error-exitcode=1 $push_swap_executable $input_numbers 2>&1)
    
    # Controlla se ci sono memory leaks in push_swap
    if echo "$push_swap_output" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts"; then
        echo "✅🤟 Valgrind test passato su push_swap:  [$input_numbers] non ci sono memory leaks."
    else
        echo "⛔🤡 Valgrind test fallito su push_swap: [$input_numbers] ci sono memory leaks."
        echo "Output di Valgrind su push_swap:"
        echo "$push_swap_output"
        return
    fi

    # Esegui il push_swap con gli argomenti passati e passa l'output al checker
    checker_output=$(echo "$push_swap_output" | $checker_executable $input_numbers 2>&1)

    # Esegui il checker con gli argomenti passati sotto la supervisione di Valgrind
    valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 $push_swap_executable $input_numbers 2>&1)    PID=$!
    allocs=$(echo "$valgrind_output" | grep "allocs" | awk '{print $5}')
    frees=$(echo "$valgrind_output" | grep "frees" | awk '{print $7}')

    # Calcola la differenza tra il numero di allocazioni e deallocazioni
    diff=$((allocs - frees))

    # Controlla se ci sono memory leaks
    if [ $diff -eq 0 ]; then
        echo "✅🤟 Test Passato con Valgrind:  [$input_numbers] non ci sono memory leaks."
    else
        echo "⛔🤡 Test Fallito con Valgrind: [$input_numbers] ci sono memory leaks."
        echo "Output di Valgrind:"
        echo "$valgrind_output"
    fi
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
)

# Esegui i test speciali
echo "Test con input particolari:"
test_number=0
for case in "${special_cases[@]}"; do
    ((test_number++))
    echo "Test $test_number:"
    run_test "$case"
    valgrind_test "$case"
done


# Numero di test da eseguire 
num_tests=5

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

echo "Testing completato."
