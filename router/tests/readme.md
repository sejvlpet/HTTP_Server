#To run tests, compile those source files

Hello world:
    *prints hello world to console*
    
Test bye:
    *sends request to localhost:8080/bye.html and compares result with expected*
    
Test invalid request:
    *sends request with invalid header and expects to recieve 500*
    
Test thread pool:
    *This one's kinda special. It sends 3 request at which server waits for 10 seconds,
    then sends one simple request to prove that it's beeing handled even though there are
    3 other request pending. Then sends another 3 request at which server waits and one simple.
    Waiting request fills all threads from pool and you can see simple request beeing handled
    after waiting's done.*    