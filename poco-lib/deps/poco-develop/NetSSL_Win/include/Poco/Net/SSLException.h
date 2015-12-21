//
// SSLException.h
//
// $Id$
//
// Library: NetSSL_Win
// Package: SSLCore
// Module:  SSLException
//
// Definition of the SSLException class.
//
// Copyright (c) 2006-2014, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef NetSSL_SSLException_INCLUDED
#define NetSSL_SSLException_INCLUDED


#include "Poco/Net/NetSSL.h"
#include "Poco/Net/NetException.h"


namespace Poco {
namespace Net {


POCO_DECLARE_EXCEPTION(NetSSL_Win_API, SSLException, NetException)
POCO_DECLARE_EXCEPTION(NetSSL_Win_API, SSLContextException, SSLException)
POCO_DECLARE_EXCEPTION(NetSSL_Win_API, CertificateException, SSLException)
POCO_DECLARE_EXCEPTION(NetSSL_Win_API, NoCertificateException, CertificateException)
POCO_DECLARE_EXCEPTION(NetSSL_Win_API, InvalidCertificateException, CertificateException)
POCO_DECLARE_EXCEPTION(NetSSL_Win_API, CertificateValidationException, CertificateException)
POCO_DECLARE_EXCEPTION(NetSSL_Win_API, SSLConnectionUnexpectedlyClosedException, SSLException)


} } // namespace Poco::Net


#endif // NetSSL_SSLException_INCLUDED
