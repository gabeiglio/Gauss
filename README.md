# Gauss

Gauss is a matrix library written in pure C, it is not intented to run on production, but just out of curiosity of how one would go about implementing these algorithms.

## Install and Run
```
$ git clone https://github.com/gabeiglio/Gauss.git
$ cd Gauss 
$ mkdir build
$ make gauss
```
## Features:

* Creating Matrices:
    * From Array
    * External File
    * User input (stdin)
    * Randomized Matrices
* Matrices Getters/Setters:
    * Get rows and columns
    * Set all elements to a value
    * Set the diagonal to a value
* Matrices Operations:
    * Basic Operations (Multiply, Add, Substract, Divide)
    * Swap Rows and Columns
    * Transpose
    * Remove row and columns
    * Concatenate matrices
* Linear Algebra Features
    * Calculate the determinant
    * Get the inverse of the matrix (Not yet implemented)
    * Row Echelon Form
        * Gaussian elimination (Not yet implemented)
        * Gauss-Jordan elimination (Not yet implemented)
