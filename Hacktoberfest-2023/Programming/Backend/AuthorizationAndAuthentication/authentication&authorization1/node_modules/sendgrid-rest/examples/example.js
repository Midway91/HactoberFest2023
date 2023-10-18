var Client = require('../lib/client.js').Client

// These values persist across of subsequent calls, unless overidden.
var globalRequest = require('../lib/client.js').emptyRequest
globalRequest.host = 'api.sendgrid.com'
// You must add your SendGrid API Key to your OS Environment
globalRequest.headers['Authorization'] = 'Bearer '.concat(process.env.SENDGRID_API_KEY)
var client = new Client(globalRequest)

function logResponse(response) {
  console.log(response.statusCode)
  console.log(response.body)
  console.log(response.headers)
}

// GET Collection
var requestGet = client.emptyRequest()
requestGet.method = 'GET'
requestGet.path = '/v3/api_keys'
requestGet.queryParams['limit'] = 100
requestGet.queryParams['offset'] = 0
client.API(requestGet,function (response){
  logResponse(response)
})

// POST
var requestBody = {
  'name': 'My API Key from Node.js',
  'scopes': [
    'mail.send',
    'alerts.create',
    'alerts.read'
  ]
}
var requestPost = client.emptyRequest()
requestPost.method = 'POST'
requestPost.path = '/v3/api_keys'
requestPost.body = requestBody
requestPost.headers['X-Test'] = 'test'
function createAPIKey (callback) {
  client.API(requestPost, function (response) {
    logResponse(response)
    var body = JSON.parse(response.body)
    callback(body.apiKeyId)
  })
}

createAPIKey(function (returnValue) { // This ensures we POST a new key first, to get the apiKeyId
  var apiKeyId = '/'.concat(returnValue)

  // GET SINGLE
  var requestGetSingle = client.emptyRequest()
  requestGetSingle.method = 'GET'
  requestGetSingle.path = '/v3/api_keys'.concat(apiKeyId)
  client.API(requestGetSingle, function (response) {
    logResponse(response)
  })

  // PATCH
  requestBody = {
    'name': 'A New Hope'
  }
  var requestPatch = client.emptyRequest()
  requestPatch.method = 'PATCH'
  requestPatch.path = '/v3/api_keys'.concat(apiKeyId)
  requestPatch.body = requestBody
  client.API(requestPatch, function (response) {
    logResponse(response)
  })

  // PUT
  requestBody = {
    'name': 'A New Hope',
    'scopes': [
      'user.profile.read',
      'user.profile.update'
    ]
  }
  var requestPut = client.emptyRequest()
  requestPut.method = 'PUT'
  requestPut.path = '/v3/api_keys'.concat(apiKeyId)
  requestPut.body = requestBody
  client.API(requestPut, function (response) {
    logResponse(response)
  })

  // DELETE
  var requestDelete = client.emptyRequest()
  requestDelete.method = 'DELETE'
  requestDelete.path = '/v3/api_keys'.concat(apiKeyId)
  client.API(requestDelete, function (response) {
    logResponse(response)
  })
})
