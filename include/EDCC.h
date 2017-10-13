/*************************************************************************
	> File Name: EDCC.h
	> Author: Leosocy
	> Mail: 513887568@qq.com 
	> Created Time: 2017/07/30 14:32:50
 ************************************************************************/
#ifndef __EDCC_H__
#define __EDCC_H__

#include <string>
#include <map>
#include <vector>

namespace EDCC {
    #define EDCC_SUCCESS 0
    #define EDCC_NULL_POINTER_ERROR 1

    #define EDCC_LOAD_CONFIG_FAIL 100
    #define EDCC_SAVE_CONFIG_FAIL 101

    #define EDCC_LOAD_TAINING_SET_FAIL 200

    #define EDCC_LOAD_FEATURES_FAIL 300
    #define EDCC_SAVE_FEATURES_FAIL 301

    #define EDCC_PALMPRINT_IMAGE_NOT_EXISTS 400

    #define _IN
    #define _INOUT

    typedef struct  {
        std::string identity;
        std::string imagePath;
        double score;
        size_t rank;
    } MatchResult;

    int GetTrainingSetFeatures(_IN const char *trainingSetPalmprintGroupFileName,
                               _IN const char *configFileName,
                               _IN const char *featuresOutputFileName,
                               _IN bool isIncremental = false);

    int GetTwoPalmprintMatchScore(_IN const char *firstPalmprintImagePath,
                                  _IN const char *secondPalmprintImagePath,
                                  _IN const char *configFileName,
                                  _INOUT double &score);

    int GetTopKMatchScore(_IN const char *onePalmprintImagePath,
                          _IN const char *trainingSetFeaturesOrPalmprintGroupFileName,
                          _IN const char *configFileName,
                          _IN bool isFeatures,
                          _IN size_t K,
                          _INOUT std::map<size_t, MatchResult> &topKResult);
}


#endif
