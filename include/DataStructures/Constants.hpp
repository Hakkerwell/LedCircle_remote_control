#ifndef CONSTANTS
#define CONSTANTS

// RFC7231 | Section 4
namespace REQUEST_METHOD {
	enum {
		GET,		// Transfer a current representation of the target resource
		HEAD,		// Same as GET, but only transfer the status line and header section
		POST,		// Perform resource-specific processing on the request payload
		PUT,		// Replace all current representations of the target resource with the request payload
		DELETE,		// Remove all current representations of the target resource
		CONNECT,	// Establish a tunnel to the server identified by the target resource
		OPTIONS,	// Describe the communication options for the target resource
		TRACE		// Perform a message loop-back test along the path to the target resource
	};
}

namespace MESSAGE_TYPE {
	enum {
		REQUEST,
		RESPONSE
	};
}
#endif
