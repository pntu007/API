# API_NINJAS C++ Project

This C++ project demonstrates how to use the [API Ninjas](https://api-ninjas.com/api) service to fetch data from various endpoints, including dad jokes, bucket list items, and riddles. The project utilizes the cURL library for making HTTP requests and the `nlohmann/json` library for parsing JSON responses.

## Requirements

To compile and run the project, ensure you have the following dependencies:

- **cURL**: A library used for making HTTP requests.
- **nlohmann/json**: A JSON parsing library for C++.

Create Account on [Api_Ninja](https://api-ninjas.com/api) and get the Api Key associated with the account.

### Installation of Dependencies

1. **Install cURL**:
   - On Linux: `sudo apt-get install libcurl4-openssl-dev`
   - On macOS: `brew install curl`
   - On Windows: Download from the [cURL website](https://curl.se/download.html).

2. **Install nlohmann/json**:
   - You can install it using [vcpkg](https://github.com/microsoft/vcpkg) or manually add the header file from [nlohmann/json GitHub](https://github.com/nlohmann/json).

## Compilation

To compile the C++ source code, run the following command:

```bash
g++ -o api_ninjas api_ninjas.cpp -lcurl
```

## Usage

1. Clone or download this repository.
2. Compile the source code as mentioned above.
3. Run the program:

```bash
./api_ninjas
```

### Output Example

The program will make requests to the following endpoints and print the responses:

- **Dad Joke**: A random dad joke fetched from the `dadjokes` API endpoint.
- **Bucket List**: A random item from the `bucketlist` API endpoint.
- **Riddle**: A random riddle with its title, question, and answer fetched from the `riddles` API endpoint.

Here’s an example output:

```
Joke: Why don't skeletons fight each other? They don't have the guts.
Bucket Item: Go to space.
Riddle Time
Title: What comes once in a minute, twice in a moment, but never in a thousand years?
Question: What am I?
Answer: The letter M.
```

## Code Overview

- **API_NINJAS Class**:
  - Handles making HTTP requests to the API Ninjas endpoints.
  - Defines `sendRequest` function to send GET requests to the API.
  - Implements functions for fetching data from specific endpoints: `dadJoke()`, `bucketList()`, and `riddle()`.

- **cURL Setup**:
  - Initializes cURL, sends GET requests, and handles responses.
  - Uses a callback function (`WriteCallback`) to store the received data in a string.

- **JSON Parsing**:
  - The `nlohmann/json` library is used to parse and handle the JSON responses from the API.

This project is Mine.
