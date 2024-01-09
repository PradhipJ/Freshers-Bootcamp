# Requirements Document
### User Story:
Develop a system that takes in a blood smear images and classifies those images according to the type of WBC in it. The system need not take basophil into account since it is available only in a very low percentage.
## Functional Requirements
- System should take the blood smear image as input.
- The system should implement image segmentation algorithms to extract WBCs from the blood smear image.
- Develop a classification model to classify WBCs into different types such as neutrophils, lymphocytes, monocytes and eosinophils.
- The system should perform image processing in real time and classify images.
- Design an user interface for the medical practitioners to effectively use the system.
## Non Functional Requirements
- The classification has to be accurate **(Accuracy)**
- The system should analyse the image and give the results quickly **(Performance)**
- Easily accessible user interface must be provided for the practitioners to use the system **(Accessibility)**
- The system should be compatible with various image formats used in medical imaging **(Compatibility)**
- The system should comply with medical regulations and standards **(Compliance)**