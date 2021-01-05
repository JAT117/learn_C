
int sockfd = socket(domain, type, protocol);

int setsockopt(int sockfd int level, int optname, const void*optval, socklen_t, optlen);

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int listen(int sockfd, int backlog);

int new_socket = accept(int sockfd, const sockaddr *addr, socklen_t addrlen);


//client 
int connect(int sockfd, const sockaddr *addr, socklen_t addrlen);