
#include <SiftGPU.h>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <boost/timer.hpp>

#include <GL/gl.h>

using namespace std;

int main( int argc, char** argv)
{
    SiftGPU sift;
    char* myargv[4] ={ "-fo", "-1", "-v", "1"};
    sift.ParseParam(4, myargv);
    int support = sift.CreateContextGL();
    cout<<"Checking"<<endl;
    if ( support != SiftGPU::SIFTGPU_FULL_SUPPORTED )
    {
        cerr<<"SiftGPU is not supported!"<<endl;
        return 2;
    }

    cout<<"running sift"<<endl;
    boost::timer timer;
    sift.RunSIFT( "/home/mac-ar/SiftGPU/test_siftgpu/data/test.png" );
    cout<<"siftgpu::runsift() cost time="<<timer.elapsed()<<endl;

    int num = sift.GetFeatureNum();
    cout<<"Feature number="<<num<<endl;
    vector<float> descriptors(128*num);
    vector<SiftGPU::SiftKeypoint> keys(num);
    timer.restart();
    sift.GetFeatureVector(&keys[0], &descriptors[0]);
    cout<<"siftgpu::getFeatureVector() cost time="<<timer.elapsed()<<endl;
    cv::Mat img = cv::imread("/home/mac-ar/SiftGPU/test_siftgpu/data/test.png", 0);
    int width = img.cols;
    int height = img.rows;
    timer.restart();
    sift.RunSIFT(width, height, img.data, GL_INTENSITY8, GL_UNSIGNED_BYTE);
    cout<<"siftgpu::runSIFT() cost time="<<timer.elapsed()<<endl;


    return 0;
}
