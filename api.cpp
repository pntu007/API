#include<iostream>
#include<string>
#include<curl/curl.h>
#include<nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class API_NINJAS{
    private : 
        // Callback function to handle data received from cURL
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        size_t totalSize = size * nmemb;
        ((string*)userp)->append((char*)contents, totalSize);
        return totalSize;
    }

    // Function to send HTTP GET request
    string sendRequest(const string& url, const string& apiKey) {
        string readBuffer;
        CURL* curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

            // Setting up HTTP headers
            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, ("X-Api-Key: " + apiKey).c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                cerr << "Request Failed: " << curl_easy_strerror(res) << endl;
            }

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
        return readBuffer;
    }

    string apiKey = "YOUR_API_KEY_ASSOCIATED_WITH_YOUR_ACCOUNT";
    string url = "https://api.api-ninjas.com/v1/";
    void dadJoke();
    void bucketList();
    void riddle();

    public :
    API_NINJAS(){
        dadJoke();
        bucketList();
        riddle();
    }
};

void API_NINJAS :: dadJoke() {
    string response = sendRequest(url+"dadjokes", apiKey);

    try {
        auto responseJson = json::parse(response);
        if (!responseJson.empty() && responseJson.is_array()) {
            cout << "Joke: " << responseJson[0]["joke"] << endl;
        } else {
            cerr << "Unexpected JSON format." << endl;
        }
    } catch (const json::exception& e) {
        cerr << "JSON Parsing Error: " << e.what() << endl;
    }
}

void API_NINJAS :: bucketList() {
    string response = sendRequest(url+"bucketlist", apiKey);
    try {
        auto responseJson = json::parse(response);
        if (!responseJson.empty() && responseJson.contains("item")) {
            cout << "Bucket Item: " << responseJson["item"] << endl;
        } else {
            cerr << "Unexpected JSON format." << endl;
        }
    } catch (const json::exception& e) {
        cerr << "JSON Parsing Error: " << e.what() << endl;
    }
}

void API_NINJAS :: riddle() {
    string response = sendRequest(url+"riddles", apiKey);

    try {
        auto responseJson = json::parse(response);
        if (!responseJson.empty()) {
            cout<< "Riddle Time "<<endl;
            cout << "Title: " << responseJson[0]["title"] << endl;
            cout<< "Question: "<<responseJson[0]["question"]<<endl;
            cout<<"Answer: "<<responseJson[0]["answer"]<<endl;
        } else {
            cerr << "Unexpected JSON format." << endl;
        }
    } catch (const json::exception& e) {
        cerr << "JSON Parsing Error: " << e.what() << endl;
    }
}

int main() {
    API_NINJAS api;
    return 0;
}
