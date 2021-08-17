#include <torch/torch.h>



/******************************** FMOD ***********************************/
// template <typename T>
// torch::Tensor fmod(torch::Tensor tensor, T divisor)
// {   
//     double div = static_cast<float>(divisor);
//     int n = static_cast<int>(tensor.sizes()[0]);
//     torch::Tensor arr = torch::tensor({});
//     for (int i = 0; i < n; i++)
//     {
//         torch::Tensor x = torch::tensor({torch::div(tensor[i], div).item().to<int>()});
//         torch::Tensor y = torch::mul(x, div);
        
//         torch::Tensor rem = torch::sub(tensor[i], y);
//         arr = torch::cat({arr, rem});
//     }
//     arr = arr.to(torch::kFloat32);
//     return arr; 
// }

template <typename T>
torch::Tensor fmod(torch::Tensor tensor, T divisor)
{   
    if (divisor == 0) throw 0; 
    double div = static_cast<float>(divisor);
    
    torch::Tensor x = torch::div(tensor, div).to(torch::kInt);
    torch::Tensor y = torch::mul(x, div);
    
    torch::Tensor rem = torch::sub(tensor, y);    
    torch::Tensor arr = rem.to(torch::kFloat32);
    return arr; 
}

/******************************** LINSPACE ***********************************/
template <typename T>
torch::Tensor linspace(T start, T end, T step)
{
    torch::Tensor arr = torch::tensor({start});
    if (step <= 0) throw 0; 
    torch::Tensor s = torch::tensor({start});

    torch::Tensor range = torch::sub(torch::tensor({end}), torch::tensor({start}));
    torch::Tensor div = torch::sub(torch::tensor({step}), 1);
    torch::Tensor stride = torch::div(range, div);
    int nn = static_cast<int>(step);

    for (int i=1; i<nn; i++)
    {
        s = torch::add(s, stride);
        arr = torch::cat({arr, s});
    }
    return arr;  
    
}
