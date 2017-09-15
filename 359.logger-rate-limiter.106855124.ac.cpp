class Logger {
public:
    unordered_map<string, int> logger;
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(logger.count(message)) {
            if(timestamp - logger[message] < 10) {
                return false;
            } else {
                logger[message] = timestamp;
                return true;
            }
        } else {
            logger[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */