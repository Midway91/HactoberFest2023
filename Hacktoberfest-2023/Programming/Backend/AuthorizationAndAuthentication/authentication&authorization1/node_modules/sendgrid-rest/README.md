![SendGrid Logo](https://uiux.s3.amazonaws.com/2016-logos/email-logo%402x.png)

[![Build Status](https://travis-ci.org/sendgrid/nodejs-http-client.svg?branch=master)](https://travis-ci.org/sendgrid/nodejs-http-client)
[![Email Notifications Badge](https://dx.sendgrid.com/badge/nodejs)](https://dx.sendgrid.com/newsletter/nodejs)
[![npm version](https://badge.fury.io/js/sendgrid-rest.svg)](https://www.npmjs.com/package/sendgrid-rest)
[![Twitter Follow](https://img.shields.io/twitter/follow/sendgrid.svg?style=social&label=Follow)](https://twitter.com/sendgrid)
[![GitHub contributors](https://img.shields.io/github/contributors/sendgrid/nodejs-http-client.svg)](https://github.com/sendgrid/nodejs-http-client/graphs/contributors)
[![MIT license](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)

**Quickly and easily access any RESTful or RESTful-like API.**

If you are looking for the SendGrid API client library, please see [this repo](https://github.com/sendgrid/sendgrid-nodejs).

# Announcements

All updates to this library are documented in our [CHANGELOG](https://github.com/sendgrid/nodejs-http-client/blob/master/CHANGELOG.md).

# Table of Contents
- [Installation](#installation)
- [Quick Start](#quick-start)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [How to Contribute](#contribute)
- [About](#about)
- [License](#license)

<a name="installation"></a>
# Installation

## Prerequisites

- Node.js version 0.10, 0.12 or 4

You need to have a API key to use the app. To configure the API key in the environment variables follow these steps.
 - create .env file in the root directory of the project.
 - Copy the contents of .env_sample file in to the .env file
 - Once you have obtained the API key, find the environment variable SENDGRID_API_KEY and assign your API key as it's value.
 As an example it should look like this
 ```
 SENDGRID_API_KEY='<YOUR_API_KEY>';
 ```


## Install Package

```bash
npm install sendgrid-rest
```

<a name="quick-start"></a>
# Quick Start

`GET /your/api/{param}/call`

```javascript
var Client = require('sendgrid-rest').Client
var client = new Client()
var request = client.emptyRequest()
var param = 'myparam'
request.host = 'api.example.com'
request.method = 'GET'
request.path = '/your/api/' + param + '/call'
client.API(request, function (response) {
  console.log(response.statusCode)
  console.log(response.body)
  console.log(response.headers)
})
```

`POST /your/api/{param}/call` with headers, query parameters and a request body.

```javascript
var Client = require('sendgrid-rest').Client
var client = new Client()
var request = client.emptyRequest()
request.host = 'api.example.com'
request.headers['Authorization'] = 'Bearer XXXXXX'
request.queryParams['limit'] = 100
request.queryParams['offset'] = 0
request.method = 'POST'
var param = 'myparam'
request.path = '/your/api/' + param + '/call'
requestBody = {
  'some': 0,
  'awesome': 1,
  'data': 3
}
request.body = requestBody
client.API(request, function (response) {
  console.log(response.statusCode)
  console.log(response.body)
  console.log(response.headers)
})
```

<a name="usage"></a>
# Usage

Following is an example using SendGrid. You can get your free account [here](https://sendgrid.com/free?source=nodejs-http-client).

First, update your environment with your [SENDGRID_API_KEY](https://app.sendgrid.com/settings/api_keys).

You can copy the .env_example file located in the "examples" folder to ```.env``` in your project's root.

```cp examples/.env_sample .env```

Once you have edited the file and added your API Key, you can add the variable to your environment:
```source .env```


Here is the [full working code](https://github.com/sendgrid/nodejs-http-client/blob/master/examples/example.js).

To run the example:

```bash
node examples/example
```
=======
[Library Usage Documentation](https://github.com/sendgrid/nodejs-http-client/blob/master/USAGE.md)

# Tests

Tests can be run through a [Docker](https://www.docker.com) container which is defined in the [docker-compose.yml](docker-compose.yml) file.

To run the tests, simply run `docker-compose up`.

<a name="roadmap"></a>
# Roadmap

If you are interested in the future direction of this project, please take a look at our [milestones](https://github.com/sendgrid/nodejs-http-client/milestones). We would love to hear your feedback.

<a name="contribute"></a>
# How to Contribute

We encourage contribution to our libraries, please see our [CONTRIBUTING](https://github.com/sendgrid/nodejs-http-client/blob/master/CONTRIBUTING.md) guide for details.

* [Feature Request](https://github.com/sendgrid/nodejs-http-client/blob/master/CONTRIBUTING.md#feature-request)
* [Bug Reports](https://github.com/sendgrid/nodejs-http-client/blob/master/CONTRIBUTING.md#submit-a-bug-report)
* [Improvements to the Codebase](https://github.com/sendgrid/nodejs-http-client/blob/master/CONTRIBUTING.md#improvements-to-the-codebase)

<a name="about"></a>
# About

nodejs-http-client is guided and supported by the SendGrid [Developer Experience Team](mailto:dx@sendgrid.com).

nodejs-http-client is maintained and funded by SendGrid, Inc. The names and logos for nodejs-http-client are trademarks of SendGrid, Inc.

<a name="license"></a>
# License
[The MIT License (MIT)](LICENSE.md)
