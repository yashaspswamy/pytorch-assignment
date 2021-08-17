#include <torch/torch.h>
#include <iostream>
#include <stdexcept>
#include "../inc/kernels.h"

// class Exception : public runtime_error {
//     public:
//     Exception(): runtime_error() {
//        std::cout << "Math error: Attempted to divide by Zero\n" ;
//     }
// };

void printTensor(torch::Tensor tensor){
    
    for (int i=0; i<tensor.sizes()[0]; i++){
        std::cout << tensor[i].item<float_t>() << " ,";
    }
}

int main() {
    int a[] = {1, -2, 4, 66, 34, 2};
    int b[] = {20, 3, 5, 76, 23, 3};
    int c[] = {2, 3, 3, 5, 3, 0};
    for (int i=0; i < 6; i++)
    {
        double start = static_cast<double>(a[i]);
        double end = static_cast<double>(b[i]);
        double step = static_cast<double>(c[i]);
        try
        {
            std::cout << " case:- " << i << "    (" << a[i] << " ," << b[i] << " ," << c[i] << ")   " ;
            torch::Tensor actual_data = torch::linspace(start, end, step).to(torch::kFloat32);
            torch::Tensor x = linspace<double>(start, end, step).to(torch::kFloat32);
            if (torch::allclose(x, actual_data)) 
            {
                std::cout << "\n builtin function :- " << std::endl;
                printTensor(x);
                std::cout << "\n custom function :- " << std::endl;
                printTensor(actual_data);
                std::cout << " \n Test case passed \n\n"  << std::endl;
            }
            else std::cout << "\n Test case failed \n\n"  << std::endl ;
        }
        catch (int i) {
        std::cout << "\n strep number is <= 0\n\n" << std::endl ;
        }
    }
}