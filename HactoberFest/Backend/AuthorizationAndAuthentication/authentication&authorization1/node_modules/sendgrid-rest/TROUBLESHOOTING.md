If you have a non-library SendGrid issue, please contact our [support team](https://support.sendgrid.com).

If you can't find a solution below, please open an [issue](https://github.com/sendgrid/nodejs-http-client/issues).

## Table of Contents
* [Viewing the Request Body](#request-body)

<a name="request-body"></a>
## Viewing the Request Body

When debugging or testing, it may be useful to examine the raw request body to compare against the [documented format](https://sendgrid.com/docs/API_Reference/api_v3.html).

You can do this with something like:
```javascript
var requestPost = client.emptyRequest()
requestPost.method = 'POST'
requestPost.path = '/v3/api_keys'
requestPost.body = { data: 'some test data' }
requestPost.headers['X-Test'] = 'test'

// Log request body before sending POST request.
console.log(requestPost.body)

client.API(requestPost, (response) => {
  // Log the response.
  console.log(response.statusCode)
  console.log(response.body)
  console.log(response.headers)
})
```
