#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <OBBdet.h>
#define CONF_THRESH 0.60
#define IOU_THRESH 0.50
static const char *labels[] = {"plane",
                               "baseball-diamond",
                               "bridge",
                               "ground-track-field",
                               "small-vehicle",
                               "large-vehicle",
                               "ship",
                               "tennis-court",
                               "basketball-court",
                               "storage-tank", "soccer-ball-field", "roundabout", "harbor", "swimming-pool", "helicopter"};
const int color_list[15][3] =
    {
        {216, 82, 24},
        {236, 176, 31},
        {125, 46, 141},
        {118, 171, 47},
        {76, 189, 237},
        {238, 19, 46},
        {76, 76, 76},
        {153, 153, 153},
        {255, 0, 0},
        {255, 127, 0},
        {190, 190, 0},
        {0, 255, 0},
        {0, 0, 255},
        {170, 0, 255},
        {84, 84, 0},
};
void draw_objects(cv::Mat bgr, vector<OBBInfo8> objects)
{
    cv::Mat img = bgr.clone();
    for (size_t i = 0; i < objects.size(); i++)
    {
        OBBInfo8 obj = objects[i];
        cv::Scalar color = cv::Scalar(color_list[obj.label][0], color_list[obj.label][1], color_list[obj.label][2]);
        float c_mean = cv::mean(color)[0];
        char text[256];
        sprintf(text, "%s %.1f%%", labels[obj.label], obj.conf * 100);
        int baseLine = 0;
        cv::Size label_size = cv::getTextSize(text, cv::FONT_HERSHEY_SIMPLEX, 0.4, 1, &baseLine);
        cv::Scalar txt_color;
        vector<cv::Point> poly;
        float value_x = (obj.x1 + obj.x2 + obj.x3 + obj.x4) / 4.0;
        float value_y = (obj.y1 + obj.y2 + obj.y3 + obj.y4) / 4.0;
        poly.push_back(cv::Point(obj.x1 + value_x, obj.y1 + value_y));
        poly.push_back(cv::Point(obj.x2 + value_x, obj.y2 + value_y));
        poly.push_back(cv::Point(obj.x3 + value_x, obj.y3 + value_y));
        poly.push_back(cv::Point(obj.x4 + value_x, obj.y4 + value_y));
        cv::polylines(img, poly, true, color, 4);
        cv::putText(img, text, cv::Point(obj.x1 + value_x, obj.y1 + value_y), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(255, 255, 255));
    }
    cv::imwrite("/home/crescent/GGHL_demo/deploy/ncnn/demo.png", img);
}
int main(int, char**) {
    GGHL_ncnn detector = GGHL_ncnn("/home/crescent/GGHL-Deployment/ncnn/GGHL_jit.ncnn.param", "/home/crescent/GGHL-Deployment/ncnn/GGHL_jit.ncnn.bin", false);
    //怎么样处理
    cv::Mat img = cv::imread("/home/crescent/images/P0006__1024__0___505.png");
    auto results = detector.detect(img,0.00,IOU_THRESH);
    draw_objects(img,results);
}
