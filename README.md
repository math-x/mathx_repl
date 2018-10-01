# MathX REPL

REPL/Interpreter that works on top of MathX. It focuses to provide a simple interface and easy python-like syntax. 

## Installation

### Using Makefile

1. (Optional) Install [mathx](www.github.com/math-x/mathx) for added functionality.
2. Clone this repository using `git clone https;//github.com/math-x/mathx_repl`
3. Change directory to the source `cd mathx_repl`
4. Run the setup script using `./setup.sh`
5. Run the REPL using the command `mathx` or `mathx -s` (silenced mode) or run a script using `mathx <path_to_script>`


### Using cmake

1. (Optional) Install [mathx](www.github.com/math-x/mathx) for added functionality.
2. Clone this repository using `git clone https;//github.com/math-x/mathx_repl`
3. Change directory to the source `cd mathx_repl`
4. Create a build folder to build in and enter the directory `mkdir build && cd build`
5. Invoke cmake to build repl `cmake ..`
6. Run the REPL using the command `./mathx_repl` or `./mathx_repl -s` (silenced mode) or run a script using `./mathx_repl <path_to_script>`

## Examples
	>>> 1+2
	3
	>>> 99.6*7.69
	765.924
	>>> x=(3.14*5)
	15.7
	>>> x
	15.7
	>>> y=sin(x)
	0.007963
	>>> y
	0.007963
