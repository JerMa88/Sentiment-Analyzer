#include "SentimentClassifier.h"
using namespace std;
vector<DSString> allWords;

bool SentimentClassifier::isStopWord(const DSString &word)
{
    vector<DSString> stopWords = {
        "",
        "a",
        "able",
        "about",
        "above",
        "abst",
        "accordance",
        "according",
        "accordingly",
        "across",
        "act",
        "actually",
        "added",
        "adj",
        "affected",
        "affecting",
        "affects",
        "after",
        "afterwards",
        "again",
        "against",
        "ah",
        "all",
        "almost",
        "alone",
        "along",
        "already",
        "also",
        "although",
        "always",
        "am",
        "among",
        "amongst",
        "an",
        "and",
        "announce",
        "another",
        "any",
        "anybody",
        "anyhow",
        "anymore",
        "anyone",
        "anything",
        "anyway",
        "anyways",
        "anywhere",
        "apparently",
        "approximately",
        "are",
        "aren",
        "arent",
        "arise",
        "around",
        "as",
        "aside",
        "ask",
        "asking",
        "at",
        "auth",
        "available",
        "away",
        "awfully",
        "b",
        "back",
        "be",
        "became",
        "because",
        "become",
        "becomes",
        "becoming",
        "been",
        "before",
        "beforehand",
        "begin",
        "beginning",
        "beginnings",
        "begins",
        "behind",
        "being",
        "believe",
        "below",
        "beside",
        "besides",
        "between",
        "beyond",
        "biol",
        "both",
        "brief",
        "briefly",
        "but",
        "by",
        "c",
        "ca",
        "came",
        "can",
        "cannot",
        "cant",
        "cause",
        "causes",
        "certain",
        "certainly",
        "co",
        "com",
        "come",
        "comes",
        "contain",
        "containing",
        "contains",
        "could",
        "couldnt",
        "d",
        "date",
        "did",
        "didnt",
        "different",
        "do",
        "does",
        "doesnt",
        "doing",
        "done",
        "dont",
        "down",
        "downwards",
        "due",
        "during",
        "e",
        "each",
        "ed",
        "edu",
        "effect",
        "eg",
        "eight",
        "eighty",
        "either",
        "else",
        "elsewhere",
        "end",
        "ending",
        "enough",
        "especially",
        "et",
        "et-al",
        "etc",
        "even",
        "ever",
        "every",
        "everybody",
        "everyone",
        "everything",
        "everywhere",
        "ex",
        "except",
        "f",
        "far",
        "few",
        "ff",
        "fifth",
        "first",
        "five",
        "fix",
        "followed",
        "following",
        "follows",
        "for",
        "former",
        "formerly",
        "forth",
        "found",
        "four",
        "from",
        "further",
        "furthermore",
        "g",
        "gave",
        "get",
        "gets",
        "getting",
        "give",
        "given",
        "gives",
        "giving",
        "go",
        "goes",
        "gone",
        "got",
        "gotten",
        "h",
        "had",
        "happens",
        "hardly",
        "has",
        "hasnt",
        "have",
        "havent",
        "having",
        "he",
        "hed",
        "hence",
        "her",
        "here",
        "hereafter",
        "hereby",
        "herein",
        "heres",
        "hereupon",
        "hers",
        "herself",
        "hes",
        "hi",
        "hid",
        "him",
        "himself",
        "his",
        "hither",
        "home",
        "how",
        "howbeit",
        "however",
        "hundred",
        "i",
        "id",
        "ie",
        "if",
        "ill",
        "im",
        "immediate",
        "immediately",
        "importance",
        "important",
        "in",
        "inc",
        "indeed",
        "index",
        "information",
        "instead",
        "into",
        "invention",
        "inward",
        "is",
        "isnt",
        "it",
        "itd",
        "itll",
        "its",
        "itself",
        "ive",
        "j",
        "just",
        "k",
        "keep",
        "keeps",
        "kept",
        "kg",
        "km",
        "know",
        "known",
        "knows",
        "l",
        "largely",
        "last",
        "lately",
        "later",
        "latter",
        "latterly",
        "least",
        "less",
        "lest",
        "let",
        "lets",
        "like",
        "liked",
        "likely",
        "line",
        "little",
        "Ill",
        "look",
        "looking",
        "looks",
        "ltd",
        "m",
        "made",
        "mainly",
        "make",
        "makes",
        "many",
        "may",
        "maybe",
        "me",
        "mean",
        "means",
        "meantime",
        "meanwhile",
        "merely",
        "mg",
        "might",
        "million",
        "miss",
        "ml",
        "more",
        "moreover",
        "most",
        "mostly",
        "mr",
        "mrs",
        "much",
        "mug",
        "must",
        "my",
        "myself",
        "n",
        "na",
        "name",
        "namely",
        "nay",
        "nd",
        "near",
        "nearly",
        "necessarily",
        "necessary",
        "need",
        "needs",
        "neither",
        "never",
        "nevertheless",
        "new",
        "next",
        "nine",
        "ninety",
        "no",
        "nobody",
        "non",
        "none",
        "nonetheless",
        "noone",
        "nor",
        "normally",
        "nos",
        "not",
        "noted",
        "nothing",
        "now",
        "nowhere",
        "o",
        "obtain",
        "obtained",
        "obviously",
        "of",
        "off",
        "often",
        "oh",
        "ok",
        "okay",
        "old",
        "omitted",
        "on",
        "once",
        "one",
        "ones",
        "only",
        "onto",
        "or",
        "ord",
        "other",
        "others",
        "otherwise",
        "ought",
        "our",
        "ours",
        "ourselves",
        "out",
        "outside",
        "over",
        "overall",
        "owing",
        "own",
        "p",
        "page",
        "pages",
        "part",
        "particular",
        "particularly",
        "past",
        "per",
        "perhaps",
        "placed",
        "please",
        "plus",
        "pm",
        "poorly",
        "possible",
        "possibly",
        "potentially",
        "pp",
        "predominantly",
        "present",
        "previously",
        "primarily",
        "probably",
        "promptly",
        "proud",
        "provides",
        "put",
        "q",
        "que",
        "quickly",
        "quite",
        "qv",
        "r",
        "ran",
        "rather",
        "rd",
        "re",
        "readily",
        "really",
        "recent",
        "recently",
        "ref",
        "refs",
        "regarding",
        "regardless",
        "regards",
        "related",
        "relatively",
        "research",
        "respectively",
        "resulted",
        "resulting",
        "results",
        "right",
        "run",
        "s",
        "said",
        "same",
        "saw",
        "say",
        "saying",
        "says",
        "sec",
        "section",
        "see",
        "seeing",
        "seem",
        "seemed",
        "seeming",
        "seems",
        "seen",
        "self",
        "selves",
        "sent",
        "seven",
        "several",
        "shall",
        "she",
        "shed",
        "shell",
        "shes",
        "should",
        "shouldnt",
        "show",
        "showed",
        "shown",
        "showns",
        "shows",
        "significant",
        "significantly",
        "similar",
        "similarly",
        "since",
        "six",
        "slightly",
        "so",
        "some",
        "somebody",
        "somehow",
        "someone",
        "somethan",
        "something",
        "sometime",
        "sometimes",
        "somewhat",
        "somewhere",
        "soon",
        "sorry",
        "specifically",
        "specified",
        "specify",
        "specifying",
        "still",
        "stop",
        "strongly",
        "sub",
        "substantially",
        "successfully",
        "such",
        "sufficiently",
        "suggest",
        "sup",
        "sure 	t",
        "take",
        "taken",
        "taking",
        "tell",
        "tends",
        "th",
        "than",
        "thank",
        "thanks",
        "thanx",
        "that",
        "thatll",
        "thats",
        "thatve",
        "the",
        "their",
        "theirs",
        "them",
        "themselves",
        "then",
        "thence",
        "there",
        "thereafter",
        "thereby",
        "thered",
        "therefore",
        "therein",
        "therell",
        "thereof",
        "therere",
        "theres",
        "thereto",
        "thereupon",
        "thereve",
        "these",
        "they",
        "theyd",
        "theyll",
        "theyre",
        "theyve",
        "think",
        "this",
        "those",
        "thou",
        "though",
        "thoughh",
        "thousand",
        "throug",
        "through",
        "throughout",
        "thru",
        "thus",
        "til",
        "tip",
        "to",
        "together",
        "too",
        "took",
        "toward",
        "towards",
        "tried",
        "tries",
        "truly",
        "try",
        "trying",
        "ts",
        "twice",
        "two",
        "u",
        "un",
        "under",
        "unfortunately",
        "unless",
        "unlike",
        "unlikely",
        "until",
        "unto",
        "up",
        "upon",
        "ups",
        "us",
        "use",
        "used",
        "useful",
        "usefully",
        "usefulness",
        "uses",
        "using",
        "usually",
        "v",
        "value",
        "various",
        "Ive",
        "very",
        "via",
        "viz",
        "vol",
        "vols",
        "vs",
        "w",
        "want",
        "wants",
        "was",
        "wasnt",
        "way",
        "we",
        "wed",
        "welcome",
        "went",
        "were",
        "werent",
        "weve",
        "what",
        "whatever",
        "whatll",
        "whats",
        "when",
        "whence",
        "whenever",
        "where",
        "whereafter",
        "whereas",
        "whereby",
        "wherein",
        "wheres",
        "whereupon",
        "wherever",
        "whether",
        "which",
        "while",
        "whim",
        "whither",
        "who",
        "whod",
        "whoever",
        "whole",
        "wholl",
        "whom",
        "whomever",
        "whos",
        "whose",
        "why",
        "widely",
        "willing",
        "wish",
        "with",
        "within",
        "without",
        "will",
        "wont",
        "words",
        "world",
        "would",
        "wouldnt",
        "www",
        "x",
        "y",
        "yes",
        "yet",
        "you",
        "youd",
        "youll",
        "your",
        "youre",
        "yours",
        "yourself",
        "yourselves",
        "youve",
        "z",
        "zero",
    };

    for (const auto &stopWord : stopWords)
    {
        if (word.toLower() == stopWord)
        {
            return true;
        }
    }
    return false;
}

DSString SentimentClassifier::stemWord(const DSString &word)
{
    // Simplified stemming logic
    DSString stemmedWord = word;
    if (stemmedWord[0] == '@' || stemmedWord[0] == '#')
    {
        return "";
    }
    if (stemmedWord[0] == 'h' && stemmedWord[1] == 't' && stemmedWord[2] == 't' && stemmedWord[3] == 'p')
    {
        return "";
    }
    size_t i = 0;
    while (i < stemmedWord.length())
    {
        char c = stemmedWord[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        {
            for (size_t j = i; j < stemmedWord.length() - 1; ++j)
            {
                stemmedWord[j] = stemmedWord[j + 1];
            }
            stemmedWord.resize(stemmedWord.length() - 1);
        }
        else
        {
            ++i;
        }
    }
    stemmedWord[stemmedWord.length()] = '\0'; // Null-terminate the string

    DSString result;
    for (size_t i = 0; i < stemmedWord.length(); ++i)
    {
        char c = stemmedWord[i];
        if (c >= 'A' && c <= 'Z')
        {
            result = result + (c - 'A' + 'a');
        }
    }
    stemmedWord = result;

    // stemmedWord.stemming();
    // stemmedWord.remove_repeat_chars();
    return stemmedWord;
}

int SentimentClassifier::train(DSString file)
{
    ifstream fileIO;
    DSString bufferString;

    cout << "Training data based on " << file << "\n";
    fileIO.open(file.c_str());
    getline(fileIO, bufferString);
    // cout << bufferString << endl << endl;
    if (!fileIO.is_open())
    {
        cout << "Could not open file" << endl;
        return 1;
    }

    cout << "Opened file successfully!" << endl;

    DSString tweetString;
    while (getline(fileIO, tweetString))
    {
        //          cout << tweetString << endl;
        int commas = 0;

        for (size_t i = 0; i < tweetString.length(); ++i)
        {
            if (tweetString[i] == ',')
            {
                ++commas;
                if (commas > 4)
                {
                    DSString fullTweet = tweetString.substring(i + 1, tweetString.length() - i);
                    //              cout << fullTweet << endl;
                    int numChars = 1;
                    for (size_t currentIndex = 0; currentIndex < fullTweet.length(); ++currentIndex)
                    {
                        if (fullTweet[currentIndex] == ' ')
                        {

                            int start = (currentIndex + 1) - numChars;
                            DSString tokenTest = fullTweet.substring(start, numChars);
                            tokenTest = tokenTest.toLower();
                            tokenTest.remove_punctuation();
                            tokenTest.remove_repeat_chars();

                            if (isStopWord(tokenTest))
                            {
                                //              cout << "STOP WORD: " << tokenTest << endl;
                                numChars = 1;
                                break;
                            }

                            bool found = false;
                            for (auto &word : allWords)
                            {
                                if (word == tokenTest && tweetString[0] == '4')
                                {
                                    word.positive();
                                    found = true;
                                    //          cout << "FOUND POSITIVE WORD: " << word << endl;
                                    break; // Stop iterating when word is found
                                }
                                else if (word == tokenTest && tweetString[0] == '0')
                                {
                                    word.negative();
                                    found = true;
                                    //          cout << "FOUND NEGATIVE WORD: " << word << endl;
                                    break; // Stop iterating when word is found
                                }
                                //          cout << "\t\t\t\tword: " << word << " index: " << allWords.size() - 1 << " of allWords. Sentiment: " << word.getSentiment() << endl;
                            }

                            if (!found)
                            {
                                string stdString = tokenTest.toString();
                                Stemmer::stem(stdString);
                                tokenTest = stdString.c_str();

                                if (tweetString[0] == '4')
                                {
                                    tokenTest.positive();
                                }
                                else if (tweetString[0] == '4')
                                {
                                    tokenTest.negative();
                                }

                                allWords.push_back(tokenTest);
                                //              cout << "PUSHED BACK: " << tokenTest << endl;
                            }

                            numChars = 1;
                        }
                        else
                        {
                            numChars++;
                        }
                    }
                }
            }
        }
    }

    fileIO.close();
    return 0;
}

void SentimentClassifier::printAllWords()
{
    cout << allWords.size() << endl;
    for (auto &word : allWords)
    {
        cout << word << "(" << word.getSentiment() << ") ";
    }
}

int SentimentClassifier::test(DSString test_file, DSString results_file)
{
    ifstream fileIO;
    DSString bufferString;
    tweet parsingTweet;
    vector<tweet> allTweets;

    cout << "testing data based on " << test_file << "\n";
    fileIO.open(test_file.c_str());
    getline(fileIO, bufferString);

    if (!fileIO.is_open())
    {
        cout << "Could not open file" << endl;
        return 1;
    }
    else
    {
        cout << "Opened file successfully!" << endl;
    }

    while (getline(fileIO, parsingTweet))
    {
        int commas = 0;
        parsingTweet.setID();

        for (size_t i = 0; i < parsingTweet.length(); ++i)
        {
            if (parsingTweet[i] == ',')
            {
                ++commas;
                if (commas == 4)
                {
                    parsingTweet.setLine(i + 1, parsingTweet.length() - i);
                    tweet actualTweet;
                    actualTweet.setContent(parsingTweet.getContent(), parsingTweet.getID());
                    actualTweet.tokenize();
                    // cout << actualTweet.getContent() << endl;
                    allTweets.push_back(actualTweet);
                }
            }
        }
    }

    fileIO.close();

    ofstream outputFile;
    cout << "Output result of testing to " << results_file << "\n";
    outputFile.open(results_file.c_str());

    // cout << allTweets.size() << endl;
    // for (auto &word : allTweets)
    // {
    //     cout << word.getContent() << "(" << ") ";
    // }

    outputFile << "Sentiment,id" << endl;
    for (const auto &tweet : allTweets)
    {
        int totalSentiment = 0;
        bool tweetSentiment = false;
        DSString string = tweet.getContent();
        // cout << string << endl;

        vector<DSString> tokens;
        int numChars = 1;
        for (size_t currentIndex = 0; currentIndex < string.length(); ++currentIndex)
        { // cuts off first character
            if (string[currentIndex] == ' ')
            {
                int start = (currentIndex + 1) - numChars;
                DSString token = string.substring(start, numChars);
                numChars = 1;
                // cout << token << endl;
                tokens.push_back(token);
            }
            numChars++;
        }

        for (auto &word : tokens)
        {
            word = word.toLower();
            word.remove_punctuation();
            word.remove_repeat_chars();

            std::string stdString = word.toString();
            Stemmer::stem(stdString);
            word = stdString.c_str();

            auto it = std::find_if(allWords.begin(), allWords.end(), [&](const DSString &elem)
                                   { return elem == word; });
            if (it != allWords.end())
            {
                // Word found in allWords vector, add its sentiment
                size_t index = std::distance(allWords.begin(), it);
                totalSentiment += allWords[index].getSentiment();
                // cout << "I am in each tokens! " << totalSentiment << "\t" << word << "\t" << allWords[index].getSentiment() << endl;
            }
        }

        if (totalSentiment > 0)
        {
            tweetSentiment = true;
        }
        if (tweetSentiment == true)
        {
            outputFile << "4," << tweet.getID() << endl;
        }
        else if (tweetSentiment == false)
        {
            outputFile << "0," << tweet.getID() << endl;
        }
    }

    outputFile.close();
    cout << "Result output complete!\n";

    return 0;
}

double SentimentClassifier::accuracy(DSString answer_file, DSString key_file)
{
    ifstream outputFile(answer_file.c_str());
    ifstream testSentimentFile(key_file.c_str());

    if (!outputFile.is_open() || !testSentimentFile.is_open())
    {
        cout << "Could not open files" << endl;
        return 0.0;
    }

    string outputLine, testSentimentLine;
    int totalTweets = 0;
    int correctPredictions = 0;

    // Skip the headers
    getline(outputFile, outputLine);
    getline(testSentimentFile, testSentimentLine);

    while (getline(outputFile, outputLine) && getline(testSentimentFile, testSentimentLine))
    {
        stringstream outputSS(outputLine);
        stringstream testSentimentSS(testSentimentLine);

        string outputSentiment, testSentiment;

        // Extract the sentiment values
        getline(outputSS, outputSentiment, ',');
        getline(testSentimentSS, testSentiment, ',');

        // Compare the sentiment values
        if (outputSentiment == testSentiment)
        {
            correctPredictions++;
        }

        totalTweets++;
    }

    outputFile.close();
    testSentimentFile.close();

    // Calculate the accuracy percentage
    double accuracy = (static_cast<double>(correctPredictions) / totalTweets) * 100.0;

    return accuracy;
}
