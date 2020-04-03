#ifndef __B_SPLINE__
#define __B_SPLINE__

#include <vector>


/**
 * @brief calc_b_spline_coefficient
 * @param max_control_point_cnt_idx
 * control point的最大下标，从0开始，所以，control point的数量为 max_control_point_cnt_idx+1
 * @param p
 * degree
 * @param max_knots_idx
 * knots的最大下标，所以，knots的数量为 max_knots_idx+1
 * @param knots
 * 具体的konts数量
 * @param u
 * @param coeffis
 * 计算返回的系数 ，长度为 max_control_point_cnt_idx+1
 */
void calc_b_spline_coefficient(int max_control_point_cnt_idx,int p,int max_knots_idx,float* knots,float u,std::vector<float>& coeffis);


#endif
