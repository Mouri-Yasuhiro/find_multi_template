#include <find_multi_tamplate.hpp>

int main(int argc, char** argv){
  //元画像と検出画像の追加
  cv::Mat src = cv::imread("../picture/src.png", 1);
  cv::Mat tmp = cv::imread("../picture/template.png", 1);

  //マッチング結果の画像と出力用画像の宣言
  cv::Mat result, dist;
  src.copyTo(dist);
  //テンプレートマッチングの実行
  cv::matchTemplate(src, tmp, result, cv::TM_CCOEFF_NORMED);

  //最大値を持つ画素の検索
  double val;
  cv::Point loc;
  cv::minMaxLoc(result,NULL,&val,NULL,&loc);

  for(int i=0;i<FIND_TARGET_NUM && fabs(val) > THRESHOLD; ++i){

    //検出部分のマスク
    cv::rectangle(result, cv::Point(loc.x-tmp.cols/2,loc.y-tmp.rows/2), cv::Point(loc.x+tmp.cols/2, loc.y+tmp.rows/2), cv::Scalar(0), -1);
    //出力用画像への描画
    cv::rectangle(dist, cv::Point(loc.x,loc.y), cv::Point(loc.x+tmp.cols, loc.y+tmp.rows), cv::Scalar(0,0,255), 2);
    //再度最大値を持つ画素の検索
    cv::minMaxLoc(result,NULL,&val,NULL,&loc);
  }

  //結果画像の出力
  cv::imwrite("../picture/output.png", dist);

  return 0;
}