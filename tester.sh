#!/bin/bash

# Percorso degli eseguibili
push_swap_executable="./push_swap"
checker_executable="./checker"

# Funzione per eseguire un singolo test
run_test() {
    input_numbers="$1"

    # Esegui il programma push_swap con gli argomenti passati e redirigi l'output su /dev/null
    push_swap_output=$($push_swap_executable $input_numbers 2> /dev/null)
    # Passa l'output di push_swap al programma checker tramite pipe e passa gli stessi argomenti, redirigendo anche l'output di checker su /dev/null
    checker_output=$(echo "$push_swap_output" | $checker_executable $input_numbers 2> /dev/null)


    # Controlla se sia l'output di push_swap che di checker sono "Error"
    push_swap_stderr=$($push_swap_executable $input_numbers  2>&1 )
    checker_stderr=$(echo "$push_swap_output" | $checker_executable $input_numbers  2>&1)

    if [ "$push_swap_stderr" = "Error" ] && [ "$checker_stderr" = "Error" ]; then
        echo "⛔🤡Test fallito: [$input_numbers] gli input inseriti non sono validi, si è verificato un errore."
    elif [ "$checker_output" = "OK" ]; then
        echo "✅🤟 Test Passato:  [$input_numbers] è stato ordinato correttamente."
    elif [ -z "$push_swap_output" ] && [ -z "$checker_output" ]; then
        echo "✅🤟 Test Superato: [$input_numbers] i numeri sono gia ordinati"
    else 
        echo "⛔🤡 Test Fallito: [$input_numbers] non è stato ordinato correttamente."
        echo "Output del checker: $checker_output"
    fi

}

# Esegui una serie di test con diversi input e output attesi
#Qui puoi aggiungere quante righe vuoi, ciascuna rappresenta un test
#run_test "3 2 1 4 5 6" 
#run_test "1" 

#minisolver tester
run_test "1 2" 
run_test "2 1" 
run_test "1 2 3" 
run_test "3 2 1" 
run_test "3 2 -12" 
run_test "3 2 1 4" 
run_test "1 2 3 4" 
run_test "1 2 3 4 5" 
run_test "5 4 3 2 1" 
run_test "4 2 1 5 3"
#big solver tester 6 - 20
run_test "1 2 6 3 5 4 7"
run_test "1 2 6 3 5 4 7 98"
run_test "12 13 7 11 2 4 6 8 10 1 9 5 3 14 15"
run_test "10 4 11 13 20 18 16 12 6 15 17 14 1 8 5 2 3 9 19 7"
run_test "15 6 13 7 2 11 12 10 8 14 16 9 18 3 17 1 4 5"
#big solver tester 20 - 50
run_test "14 28 8 11 2 23 29 25 13 1 16 15 26 6 10 27 18 9 20 19 21 22 4 3 5 12 7 17 30 24"
run_test "3 15 23 30 12 16 35 4 6 39 5 17 22 7 14 36 24 38 27 34 18 37 13 31 32 9 28 20 1 40 10 29 33 19 2 21 25 8 11 26"
run_test "7 24 36 19 4 31 15 9 28 42 13 20 29 27 22 38 40 5 17 16 37 35 32 2 12 33 14 41 44 43 3 30 39 8 26 25 23 21 10 11 1 34 45 18 6"
run_test "28 34 27 42 44 8 5 47 46 3 6 12 30 19 33 11 29 1 38 16 32 9 26 40 45 43 50 21 7 18 23 39 20 37 14 31 2 24 35 36 48 13 17 10 25 4 22 15 41 49"
#big solver tester 50 - 100
run_test "9 20 11 12 36 10 51 5 49 16 27 39 44 34 32 47 37 7 33 19 43 41 13 2 24 14 29 23 21 40 17 38 4 28 50 25 42 22 3 15 35 6 31 1 45 18 48 30 8 26 46"
run_test ""

run_test "2 1 4 21 34 53 2 5 12"
run_test "2 1 4 21 34 53 5 12" 
run_test "+0 -0"
run_test "1 + -2"
run_test "dasd"

# Aggiungi altri test se necessario

echo "Testing completato."
