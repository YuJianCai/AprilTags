#ifndef TAGDETECTOR_H
#define TAGDETECTOR_H

#include <vector>

#include "opencv2/opencv.hpp"

#include "AprilTags/FloatImage.h"
#include "AprilTags/TagDetection.h"
#include "AprilTags/TagFamily.h"

namespace AprilTags {

class TagDetector {
 public:
  const TagFamily thisTagFamily;

  //! Constructor
  // note: TagFamily is instantiated here from TagCodes
  TagDetector(const TagCodes& tagCodes, const size_t blackBorder = 1)
      : thisTagFamily(tagCodes, blackBorder) {}

  std::vector<TagDetection> extractTags(const cv::Mat& image);
};

}  // namespace AprilTags

#endif
