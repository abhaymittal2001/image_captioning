# image_captioning
The objective of the project is to predict the captions for the input image. The dataset consists of 8k images and 5 captions for each image. The features are extracted from both the image and the text captions for input. The features will be concatenated to predict the next word of the caption. CNN is used for images and LSTM is used for text. But the predicted captions were not much similar to the actual captions.  The BLUE score was 0.51. Later Applied the transformer architecture and used the Inception V3 model instead of VGG 16 model for image Feature Extraction. Then the BLUE Score was 0.7 and the predicted captions were very much similar to actual captions. 

This Image captioning algorithm typically involves the use of a convolutional neural network (CNN) to extract features from an input image, and a recurrent neural network (RNN) to generate captions from the extracted features. The CNN typically starts with a pre-trained ImageNet model, which is then fine-tuned on a large dataset of images with corresponding captions. The RNN is usually an LSTM or GRU cell, which takes in the features extracted by the CNN and outputs a sequence of words. The CNN and RNN are usually jointly trained end-to-end, such that the features extracted by the CNN are optimized for the task of caption generation. Once trained, the image captioning model can be used to generate captions for any input image. 
 Transformer architecture consists of 2 Model
 * TransformerEncoder: The extracted image features are then passed to a Transformer
 * A TransformerDecoder: This model takes the encoder output and the text data
# Libraries
* Matpotlib
* Keras
* Numpy
* Pandas
* Tensorflow

