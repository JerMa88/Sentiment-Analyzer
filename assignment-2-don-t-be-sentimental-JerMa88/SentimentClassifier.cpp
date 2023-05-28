#include "SentimentClassifier.h"
using namespace std;

SentimentClassifier::SentimentClassifier()
{
    trainingAccuracy = 0;
    testingAccuracy = 0;
}

// SentimentClassifier(const SentimentClassifier &other)
// {

// }

SentimentClassifier &operator=(const SentimentClassifier &other)
{
    this->theDictionary = other.theDictionary;
    this->parameters = other.parameters;
    this->trainingAccuracy = other.trainingAccuracy;
    this->testingAccuracy = other.testingAccuracy;
    this->testPredictions = other.testPredictions;
    this->testIDs = other.testIDs;
    this->incorrectIndices = other.incorrectIndices;
}

DataFrame Twitter::read_tweets(DSString filename)
{
    DataFrame df2D;
    DSVector<DSString> df1D;

    // Read in file
    ifstream file;
    file.open(filename.c_str());

    // Try, catch
    if (!file.is_open())
    {
        throw runtime_error("Input file not open!");
    }

    cout << "   Reading Tweets [==      ][1/4]..." << endl;

    stringstream buffer; // Declare stringstream buffer
    buffer << infile.rdbuf();

    file.close(); // close the file after reading everything

    // .str().c_str() converts buffer into a c_string, which is compatible with operator= for DSString
    DSString data = buffer.str().c_str();

    cout << "   Reading Tweets [====    ][2/4]..." << endl;

    // Reference .split() in DSString class
    df1D = data.split('\n');

    cout << "   Reading Tweets [======  ][3/4]..." << endl;

    size_t colCounter = 1;

    for (int i = 0; i < df1D[0].size(); ++i)
    {
        if (df1D[0][i] == ',')
            colCounter++;
    }

    // Column separating for-loop
    for (auto row : df1D)
    {
        DSVector<DSString> tmp = row.split(',', colCounter);
        df2D.push_back(tmp);
    }

    cout << "   Reading Tweets [========][4/4]..." << endl;

    return df2D;
}

void removeStopWords(vector<vector<DSString>> &tweets)
{
    vector<DSString> stopWords(732);
    vector<DSString> cleanedStopWords;

    // Read in file
    // Data sources:

    ifstream file;
    file.open("data/stopwords.csv");

    // Try, catch
    if (!file.is_open())
    {
        throw runtime_error("Stop words file is not open!");
    }

    stringstream buffer; // Declare stringstream buffer
    buffer << file.rdbuf();

    file.close(); // close the file after reading everything

    // .str().c_str() converts buffer into a c_string, which is compatible with operator= for DSString
    DSString data = buffer.str().c_str();

    // Reference .split() in DSString class
    stopWords = data.split(',');

    // Create copy of stopWords to generate cleaned versions, then append them to stopWords DSVector
    cleanedStopWords = stopWords;
    for (int i = 0; i < cleanedStopWords.size(); ++i)
    {
        cleanedStopWords[i].stemming();
        cleanedStopWords[i].remove_repeat_chars();
        stopWords.push_back(cleanedStopWords[i]);
    }

    // Ensure that all stop words in our stop dataset are removed to lessen overfitting
    for (int i = 0; i < stopWords.size(); ++i)
        for (int j = 0; j < tweetWordsList.size(); ++j)
            for (int k = 0; k < tweetWordsList[j].size(); ++k)
                if (stopWords[i] == tweetWordsList[j][k])
                    tweetWordsList[j].remove(k);
}

vector<vector<DSString>> tokenizedTweets(DataFrame tweets)
{
    cout << "   Cleaning Tweets [===      ][1/3]..." << endl;

    vector<int> shape(2);
    shape[0] = df.size();

    // Runtime Error if we aren't observing the Tweet column
    if (df[0][-1] != "Tweet")
        throw runtime_error("tokenizedTweets() in SentimentClassifier class failed! Not analyzing sentiment column!");

    vector<vector<DSString>> tweetWordsList;

    // i=1 so we don't include the column title
    for (size_t i = 1; i < shape[0]; ++i) {
        // Create buffer vector that holds words in individual Tweet
        vector<DSString> buffer;

        // Implement cleaning functions in DSString and assign result to buffer
        buffer = df[i][-1].to_lower().remove_punctuation().split(' ');

        for (int j = 0; j < buffer.size(); ++j) {
            buffer[j].stemming();
            buffer[j].remove_repeat_chars();
        }

        tweetWordsList.push_back(buffer);

        if (i == shape[0] / 2)
            cout << "   Cleaning Tweets [======   ][2/3]..." << endl;

    }

    remove_stop_words(tweetWordsList);

    cout << "   Cleaning Tweets [=========][3/3]..." << endl;

    return tweetWordsList;

}

vector<DSString> sentimentLable(DataFrame tweets)
{
    vector<DSString> sentiments;

    // Runtime Error if we aren't observing the Sentiment column
    if (df[0][0] != "Sentiment")
        throw runtime_error("sentimentLable() in SentimentClassifier class failed! Not analyzing sentiment column!");

    for (int i = 1; i < df.size(); ++i)
        sentiments.push_back(df[i][0]);
    

    return sentiments;
}
// vector<Word> dataBase(vector<vector<DSString>> tweets, vector<DSString> sentiments);

double Twitter::training_accuracy(DSVector<double> parameters,
                                  DSVector<DSVector<double>> X,
                                  DSVector<DSString> strSentiments)
{
    // Input actual numeric solutions into the y DSVector
    DSVector<double> y;
    for (int i = 0; i < strSentiments.size(); ++i) {
        if (strSentiments[i] == "4")
            y.push_back(1.0);
        else if (strSentiments[i] == "0")
            y.push_back(0.0);
        else
            throw runtime_error("Sentiment element is neither positive nor negative in Twitter::gradient_descent()");
    }

    int correctNum = 0;
    int total = strSentiments.size();

    // Increment correct predictions
    for (int i = 0; i < X.size(); ++i) {
        double p = parameters[0]
                   + (parameters[1] * X[i][1])
                   + (parameters[2] * X[i][2]);
        double y_hat = sigmoid(p);
        if (abs(y_hat - y[i]) <= 0.5)
            correctNum++;
    }

    double percentAccuracy = 100 * (double(correctNum) / double(total));

    return percentAccuracy;

}


double Twitter::testing_accuracy(DSVector<double> parameters,
                                 DSVector<DSVector<double>> X,
                                 DSVector<DSString> strSentiments,
                                 DSVector<DSString> IDs) {
    // Input actual numeric solutions into the y DSVector
    DSVector<double> y;
    for (int i = 0; i < strSentiments.size(); ++i) {
        if (strSentiments[i] == "4")
            y.push_back(1.0);
        else if (strSentiments[i] == "0")
            y.push_back(0.0);
        else
            throw runtime_error("Sentiment element is neither positive nor negative in Twitter::gradient_descent()");
    }

    int correctNum = 0;
    int total = y.size();

    DSVector<int> anomalyIncides;

    DSVector<DSString> predictions;
    // Increment correct predictions
    for (int i = 0; i < X.size(); ++i) {
        double p = parameters[0]
                   + (parameters[1] * X[i][1])
                   + (parameters[2] * X[i][2]);
        double y_hat = sigmoid(p);
        if (abs(y_hat - y[i]) <= 0.5) {
            correctNum++;
            if (y[i] == 1)
                predictions.push_back("4");
            else if (y[i] == 0)
                predictions.push_back("0");
        }
        else {
            // Keep a log of all incides where incorrect predictions occur
            anomalyIncides.push_back(i);
            if (y[i] == 1)
                predictions.push_back("0");
            else if (y[i] == 0)
                predictions.push_back("4");
        }
    }

    double percentAccuracy = 100 * (double(correctNum) / double(total));


    // Identify anomaly cases and assign these cases to global variables
    DSVector<DSString> anomalyPredictions;
    DSVector<DSString> anomalyIDs;
    for (const auto i : anomalyIncides)
        anomalyIDs.push_back(IDs[i]);

    // Push these values to Twitter object's private variable
    setIncorrectIndices(anomalyIncides);
    setTestPredictions(predictions);
    setTestIDs(IDs);


    return percentAccuracy;
}


void SentimentClassifier::train(DSString trainingFile) {
    cout << "Training Data..." << endl;

    // Read in the file
    DataFrame df = read_tweets(trainingFile);

    // Clean up the tweets in the file
    DSVector<DSVector<DSString>> cleanedTweets = cleaned_tweets(df);

    // Obtain the sentiments from the training set into a 1D DSVector
    DSVector<DSString> sentimentLabel = sentiment_label(df);

    // Assign a dictionary of all words and their qualities to a private variable
    setTheDictionary( dictionary(cleanedTweets, sentimentLabel) );

    // Calculate a matrix with all the training data represented quantitatively
    DSVector<DSVector<double>> numericalData = numerical_data(getTheDictionary(), cleanedTweets);
    //DSVector<DSVector<double>> standardizedData = standardize_data(numericalData);

    // Assign Logistic Regression parameters to a private DSVector
    setParameters( gradient_descent(numericalData, sentimentLabel) );

    // Assign the training accuracy to a private variable
    setTrainingAccuracy( training_accuracy(getParameters(), numericalData, sentimentLabel) );

    // Output finishing message
    cout << "   Finished Training!!!" << endl
         << "      Logistic Regression Parameters:" << endl
         << "         b0 = " << getParameters()[0] << endl
         << "         b1 = " << getParameters()[1] << endl
         << "         b2 = " << getParameters()[2] << endl
         << "   Training Accuracy: " << getTrainingAccuracy() << "%" << endl;

}


void SentimentClassifier::test(DSString testingFile, DSString resultsFile) {
    cout << "Testing Data..." << endl;

    // Read in the testing file
    DataFrame df = read_tweets(testingFile);

    // Clean up the dataset of test tweets
    DSVector<DSVector<DSString>> cleanedTweets = cleaned_tweets(df);

    // Convert DSString data into quantitative data so we can test on logisitc regression
    DSVector<DSVector<double>> numericalData = numerical_data(getTheDictionary(), cleanedTweets);
    //DSVector<DSVector<double>> standardizedData = standardize_data(numericalData);

    // Read in the results file and assign sentiments to a variable
    DataFrame testingResults = read_tweets(resultsFile);
    DSVector<DSString> sentimentAnswers = sentiment_label(testingResults);
    DSVector<DSString> listOfIDs = create_ID_list(testingResults);

    // Obtain testing accuracy and assign value to private variable
    setTestingAccuracy( testing_accuracy(getParameters(), numericalData, sentimentAnswers, listOfIDs) );

    // Output completion message
    cout << "Finished Testing!!!" << endl
         << "   Testing Accuracy: " << getTestingAccuracy() << "%" << endl;

}


void SentimentClassifier::check_results(DSString predictionsTitle, DSString resultsTitle) {
    cout << "Inserting results into 2 files..." << endl;
    ofstream predictionFile(predictionsTitle.c_str());
    ofstream resultsFile(resultsTitle.c_str());

    cout << "   Generating files [======      ][1/2]..." << endl;

    // Try, catch
    if (predictionFile.is_open() && resultsFile.is_open()) {
        predictionFile.write("Sentiment,id\n", 13);
        resultsFile << setprecision(3) << (getTestingAccuracy() / 100) << "\n";

        bool checkWrongPrediction = true;
        int errorIndex = 0;
        for (int i = 0; i < getTestPredictions().size(); ++i) {
            predictionFile << getTestPredictions()[i] << "," << getTestIDs()[i] << "\n";

            // In moments where our algorithm incorrectly predicted the tweet
            if (checkWrongPrediction) {
                if (i == getIncorrectIndices()[errorIndex]) {
                    if (getTestPredictions()[i] == "4")
                        resultsFile << "0,4," << getTestIDs()[i] << "\n";
                    else if (getTestPredictions()[i] == "0")
                        resultsFile << "4,0," << getTestIDs()[i] << "\n";
                    else
                        throw runtime_error("Private variable testPredictions contains an invalid sentiment.");

                    // Increment so we're evaluating the next error index after the loop
                    errorIndex++;

                    if (errorIndex == incorrectIndices.size())
                        checkWrongPrediction = false;
                }
            }

        }

        predictionFile.close(); // close the file after reading everything
        resultsFile.close(); // close this one as well

    }
    else {
        throw runtime_error("Input file not open!");
    }

    cout << "   Generating files [============][2/2]..." << endl
         << "Twitter Sentiment Analysis Complete!" << endl
         << "   Check " << predictionsTitle << " and " << resultsTitle << " for results!" << endl;
}