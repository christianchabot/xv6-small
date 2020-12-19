
struct iovec;

struct uio {
	struct iovec *iov;
	int iovcnt;
};
