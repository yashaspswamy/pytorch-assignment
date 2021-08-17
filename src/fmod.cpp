#include <torch/torch.h>
#include <iostream>
#include <vector>
#include "../inc/kernels.h"

void printTensor(torch::Tensor tensor){
    
    for (int i=0; i<tensor.sizes()[0]; i++){
        std::cout << tensor[i].item<float_t>() << " ,";
    }
}

void checking(torch::Tensor tensor, int divisor){
    std::cout << " case:- " << "    ( [" ;
    printTensor(tensor);
    std::cout  << "] , " << divisor << ")   " ;
    try
    {
        torch::Tensor actual_data = torch::fmod(tensor, divisor).to(torch::kFloat32);
        torch::Tensor x = fmod<int>(tensor, divisor);
        if (torch::allclose(x, actual_data))
        {
            std::cout << "\n builtin function :- " ;
            printTensor(x);
            
            std::cout << "\n custom function :- " ;
            printTensor(actual_data);
            std::cout << " \n Test case passed \n\n"  << std::endl;
        }
        else std::cout << " Test case failed "  << std::endl ;
    }
    catch (int i)  {
        std::cout << " divisor is equal to 0 " ;
    }
}

int main() {
    
    torch::Tensor x1 = torch::tensor({1.2, 7.36, 2.51, 56.2, 9.1, 4.9});   
    torch::Tensor x2 = torch::tensor({12, 6, 98, 34, 74, 23});            
    torch::Tensor x3 = torch::tensor({3.6, 4.2, 9.345, 8.61, 12.81, 1.2}); 
    torch::Tensor x4 = torch::tensor({-34, -11, -87, -65, -126, -76});


    // float x[][6] = {{1, 2.4, 6, 6, 3, 23}, {12, 6, 98, 34, 74, 23}, {111, 222, 4, 53, 5.3, 99}, {-34, -11, -87, -65, -126, -76}};
    // torch::Tensor tensors = torch::from_blob(x).to(torch::kFloat32).clone();

    int divisor[] = {2, 3, 4, 1, 0};
    
    checking(x1, divisor[0]);
    checking(x2, divisor[1]);
    checking(x3, divisor[2]);        
    checking(x4, divisor[3]);
    checking(x4, divisor[4]);
    
}