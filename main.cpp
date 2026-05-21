#include <opencv2/opencv.hpp>
#include <iostream>
#include<algorithm>
using namespace std; 

void blur_red(cv::Mat& img){
    // Inside your else block:
    int rows = img.rows;
    int cols = img.cols;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            
            // img.at<cv::Vec3b>(r, c) grabs the BGR pixel at row 'r', column 'c'
            // [2] targets the Red channel directly. Let's set it to 0 (completely off)
            img.at<cv::Vec3b>(r, c)[2] = 0; 
            
        }
    }

    // Save or display the image to see the result
    cv::imwrite("assets/no_red_output.jpg", img);
    std::cout << "Red channel eliminated and saved to assets/no_red_output.jpg" << endl;
}

int main() {
    cv::Mat img = cv::imread("assets/image1.jpg", cv::IMREAD_COLOR);

    if (img.empty()) {
        std::cout << "Failed to load image\n";
        return 1;
    } else{
        cout << "Image loaded successfully" << endl;
    }
    cout << img.cols << " x " << img.rows 
     << " with " << img.channels() << " channels" << endl;    
     
     // blur red
     blur_red(img);

    return 0;
}
