# Alice Car Shop
[Task](task.pdf)
## Run:
~~~
:~$ mkdir build
:~$ cmake -S . -B build && cmake --build build
:~$ ./build/AliceShop input_file.txt
~~~
## Algorithm:
* Firstly, algorithm finds the point from witch the observations are made, and corresponding basis.

  Gram-Schmidt process is used for this step.
  
  ![Gram-Schmidt](Pic/gram-schmidt.png)
  
  On the output of process we will have matrix(r*n), where r - rank of matrix(r <= n)
* Secondly,  we will use this basis for transforming to normal basis.

  ![transform to normal basis](Pic/basis_normalisation_first.png)

  Since B - orthogonal, we can find inverse matrix as transposed matrix.

  ![transform to normal basis](Pic/basis_normalisation_second.png)
* The third step of algorithm is finding equals between instance matrix in normal basis and matrices in database in normal basis. 


![algorithm](Pic/algorithm.png)
