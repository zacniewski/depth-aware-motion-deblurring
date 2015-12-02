#ifndef DISPARITY_ESTIMATION_H
#define DISPARITY_ESTIMATION_H

#include <opencv2/opencv.hpp>


namespace DisparityEstimation {

    /**
     * Fills occlusion regions (where the value is smaller than a given threshold) 
     * with smallest neighborhood disparity (in a row) because just relatively small 
     * disparities can be occluded.
     * 
     * @param disparityMap disparity map where occlusions will be filled
     * @param threshold    threshold for detecting occluded regions
     */
    void fillOcclusionRegions(cv::Mat &disparityMap, const int threshold = 0);

    /**
     * Uses OpenCVs semi global block matching algorithm to obtain
     * a disparity map with occlusion as black regions
     * 
     * @param left         left image
     * @param right        right image
     * @param disparityMap disparity with occlusions
     */
    void semiGlobalBlockMatching(const cv::Mat &left, const cv::Mat &right, cv::Mat &disparityMap);

    /**
     * Quantizes a given picture with kmeans algorithm and sorts the
     * clustering depending on the color value of the cluster centers
     * such that the clustering represents depth graduation.
     * 
     * @param image          input image
     * @param k              cluster number
     * @param quantizedImage clustered image
     */
    void quantizeImage(const cv::Mat& image, const int k, cv::Mat& quantizedImage);
}

#endif