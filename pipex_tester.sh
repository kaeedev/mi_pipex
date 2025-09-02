#!/bin/zsh

# Crear archivos de prueba
echo "Hola mundo" > infile.txt
echo "Otra línea" >> infile.txt

# Test 1: Comando simple
echo "Test 1: cat | wc -l"
./pipex infile.txt "cat" "wc -l" outfile1.txt
cat outfile1.txt

# Test 2: Grep y sort
echo "Test 2: grep Hola | sort"
./pipex infile.txt "grep Hola" "sort" outfile2.txt
cat outfile2.txt

# Test 3: Error de argumentos
echo "Test 3: argumentos incorrectos"
./pipex infile.txt "cat" "wc -l"

# Test 4: Archivo de entrada inexistente
echo "Test 4: archivo de entrada no existe"
./pipex noexiste.txt "cat" "wc -l" outfile3.txt

# Test 5: Comando inexistente
echo "Test 5: comando no existe"
./pipex infile.txt "noexiste" "wc -l" outfile4.txt

# Limpiar archivos generados
rm -f infile.txt outfile1.txt outfile2.txt outfile3.txt outfile4.txt