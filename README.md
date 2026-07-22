# RSA in C (Textbook RSA)

A pedagogical implementation of the RSA algorithm in C. The goal of this repository is to demonstrate and verify the step-by-step math behind "textbook RSA" in practice, without the extra security layers (like padding) required in real-world systems.

The code reads public/private keys from `.csv` files, encrypts a string into numerical blocks, and performs the reverse calculation to decrypt the message, proving the concept with an integrity check.

## Project Structure

- `arquivos/` - Input files (csv with keys and texts)
- `include/` - Headers (`rsa.h`)
- `src/` - Source code (`rsa.c`, `decodificar.c`)
- `executaveis/` - Compiled binaries

## How to run

To compile and run, enter the `src` folder and run `gcc` pointing to the headers folder:

```bash
cd src
gcc -I../include decodificar.c rsa.c -o executaveis/decodificar
./executaveis/decodificar