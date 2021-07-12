#include <find_multi_tamplate.hpp>

int main(int argc, char** argv){
  cv::Mat src = cv::imread("../picture/src.png", 1);
  cv::Mat tmp = cv::imread("../picture/template.png", 1);

  printf("x, %d, y, %d", tmp.cols,tmp.rows);

  cv::Mat result, dist;
  src.copyTo(dist);
  cv::matchTemplate(src, tmp, result, cv::TM_CCOEFF_NORMED);

  double val;
  cv::Point loc;
  cv::minMaxLoc(result,NULL,&val,NULL,&loc);

  while(fabs(val) > THRESHOLD){
    printf("x, %d, y, %d, val, %f", loc.x,loc.y, fabs(val));
    cv::imshow("result",result);
    cv::waitKey(1);
    std::cin.get();

    cv::rectangle(result, cv::Point(loc.x-tmp.cols/2,loc.y-tmp.rows/2), cv::Point(loc.x+tmp.cols/2, loc.y+tmp.rows/2), cv::Scalar(0), -1);
    cv::rectangle(dist, cv::Point(loc.x,loc.y), cv::Point(loc.x+tmp.cols, loc.y+tmp.rows), cv::Scalar(0,0,255), 2);
    cv::minMaxLoc(result,NULL,&val,NULL,&loc);
  }

  cv::imshow("result",dist);
  cv::waitKey(0);

  return 0;
}