# Prism Vectors

Prism Vectors is a bare bones, header only set of vector structs, designed to allow simple manipulation of 2d and 3d vectors. 

## Core features

- All common operators supported  
  
      `+ - * =  ++ -- /`

- Stream output for easy logging 
  
  - `pV3D myVector(10,5,6);`
  
  - `std::cout <<  myVector; `
  
  - console output: [ 10 , 5 , 6 ] 

-  Functions for commonly used Vector math.
  
  - magnitude()
  
  - crossProduct()
  
  - dotProduct()
  
  - distanceTo()
  
  - normalize()
  
  - isNullVector()

- Customizable logging, debugging and division by zero guards.

## Thats it! only what you need, none of what you don't.

#### Licence:

MIT License

Copyright (c) 2022 David Jogoo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
