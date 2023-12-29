#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;


//Example call LicensePlate /path/to/Images/licensePlate.jpeg /path/to/xmlfile /path/to/detectedPlates/
//Press 'q' to close program at any time.
int main(int argc, char* argv[]){
    //Takes image path
    //argv[1] is the path to the image you would like to detect license plates from
    string pathToImage = argv[1];
    Mat licPlate = imread(pathToImage);
    CascadeClassifier licensePlateCascades;

    //argv[2] is the xml file
    //This is the xml file from where we will read data and use it to detect the license plates in the image
    licensePlateCascades.load(argv[2]);

    //Validates that there are xml files present
    if(licensePlateCascades.empty()){
        cout << "There are no XML files loaded" << endl;
    }

    //Stores the license plates that were detected
    vector<Rect> licensePlates;

    //Detects the license plates inside the image
    licensePlateCascades.detectMultiScale(licPlate, licensePlates, 1.4, 10);

    //Loops through the license plates inside of the vector and crops them
    for(int i = 0; i<licensePlates.size(); i++){ 
        //Crops the license plates detected inside the image
        Mat croppedPlate = licPlate(licensePlates[i]);

        //Shows the cropped image to the screen
        //imshow(to_string(i), croppedPlate);

        //Saves images to detected plates folder
        //argv[3] is where the cropped images of licenseplates will be stored
        imwrite(argv[3] + to_string(i)+".png", croppedPlate);
    
        //Highlights the license plates detected inside the image
        rectangle(licPlate, licensePlates[i].tl(), licensePlates[i].br(), Scalar(255, 0, 255), 2); 
    }

    //Shows the original image where along with where the license plates are in the original image
    imshow("Image", licPlate);

    waitKey(0);
    return 0;

}
