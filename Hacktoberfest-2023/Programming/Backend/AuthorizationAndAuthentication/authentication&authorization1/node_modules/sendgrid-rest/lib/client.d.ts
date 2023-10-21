declare module 'sendgrid-rest' {
  /**
   * request holds the request to an API Call
   * @field `test` use this to allow for http calls
   * @field `port` set the port for http calls
   */
  export interface Request {
    host: string,
    method: string,
    path: string,
    headers: {[key: string]: any},
    body: object | string,
    queryParams: {[key: string]: any},
    test: boolean,
    port: string,
  }

  /**
   * response holds the response from an API call, use this as an initializer
   * like so: JSON.parse(JSON.stringify(response))
   */
  export interface Response {
    statusCode: string,
    body: object | string,
    headers: {[key: string]: any},
  }
  
  /**
   * Client allows for quick and easy access any REST or REST-like API.
   */
  export class Client {
    constructor(globalRequest: Request)
    /**
     *  utility function to create an empty request object
     */
    public emptyRequest(): Request
    /**
     * API is the main interface to the API.
     */
    public API(endpointRequest: Request, callback: (response: Response) => void): void
  }

  export var emptyRequest: Request
  export var request: Request
}