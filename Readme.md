## Running in Mac:

1. Create Make File: 
		
		cmake -DCMAKE_C_COMPILER="/usr/local/opt/llvm/bin/clang" -DCMAKE_CXX_COMPILER="/usr/local/opt/llvm/bin/clang++" .
2. To build the Project: 
		
		make

3. Make sure the executable `nnfs` is generated and to run:
		
		./nnfs
