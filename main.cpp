#include <iostream>
#include "math/b_spline.h"

using namespace std;
int basic_test_b_spline(){

    //参考http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-ex-1.html
    float knots_arr[]={ 0, 0.25, 0.5, 0.75, 1};
    int knots_size=sizeof(knots_arr) / sizeof(knots_arr[0]);
    int max_knots_idx=knots_size-1;

    std::vector<float> knots(knots_arr,knots_arr+knots_size);
    int p=1;
    float u=0.6;

    for(int i=0;i<knots.size();i++){
        std::cout<<"i="<<i<<" knots="<<knots[i]<<std::endl;
    }


    int max_control_point_cnt_idx=max_knots_idx-p-1;
    vector<float> coeffis(max_control_point_cnt_idx+1);
    calc_b_spline_coefficient(max_control_point_cnt_idx,p,max_knots_idx,knots_arr,u,coeffis);

    std::cout<<"coefficients of u="<<u<<" p="<<p<<" are as follows:\n";
    for(int i=0;i<=max_control_point_cnt_idx;i++){
        std::cout<<coeffis[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){

    basic_test_b_spline();

}


