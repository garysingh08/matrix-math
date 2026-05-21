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

vector<vector<int>> rotate_90(vector<vector<int>>& grid){
    // transpose
    int n=grid.size();

    // step 1 transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(grid[i][j], grid[j][i]);
        }
    }

    // reverse
    for(int i=0; i<n; i++){
        reverse(grid[n].begin(), grid[n].end());
    }
    return grid; 
}

cv::Mat toMat(const vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();

    cv::Mat out(H, W, CV_8UC1);

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            out.at<uchar>(r, c) = static_cast<uchar>(grid[r][c]);
        }
    }

    return out;
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
     
    // convert to matrix
    vector<vector<int>> mat(img.rows, vector<int>(img.cols));

    for (int r = 0; r < img.rows; r++) {
        for (int c = 0; c < img.cols; c++) {
            cv::Vec3b pixel = img.at<cv::Vec3b>(r, c);
            int gray = (pixel[2] + pixel[1] + pixel[0]) / 3; // R+G+B
            mat[r][c] = gray;
        }
    }

    vector<vector<int>> rotated = rotate_90(mat);

    // Convert back to cv::Mat
    cv::Mat rotatedMat = toMat(rotated);

    // Save result
    cv::imwrite("assets/rotated.jpg", rotatedMat);


    return 0;
}
