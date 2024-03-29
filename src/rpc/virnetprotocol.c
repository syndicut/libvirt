#include <config.h>
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpc/virnetprotocol.h"
#include "internal.h"
#include <arpa/inet.h>
#ifdef HAVE_XDR_U_INT64_T
# define xdr_uint64_t xdr_u_int64_t
#endif
#ifndef IXDR_PUT_INT32
# define IXDR_PUT_INT32 IXDR_PUT_LONG
#endif
#ifndef IXDR_GET_INT32
# define IXDR_GET_INT32 IXDR_GET_LONG
#endif
#ifndef IXDR_PUT_U_INT32
# define IXDR_PUT_U_INT32 IXDR_PUT_U_LONG
#endif
#ifndef IXDR_GET_U_INT32
# define IXDR_GET_U_INT32 IXDR_GET_U_LONG
#endif

bool_t
xdr_virNetMessageType (XDR *xdrs, virNetMessageType *objp)
{

         if (!xdr_enum (xdrs, (enum_t *) objp))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageStatus (XDR *xdrs, virNetMessageStatus *objp)
{

         if (!xdr_enum (xdrs, (enum_t *) objp))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageHeader (XDR *xdrs, virNetMessageHeader *objp)
{
        register int32_t *buf;


        if (xdrs->x_op == XDR_ENCODE) {
                buf = (int32_t*)XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
                if (buf == NULL) {
                         if (!xdr_u_int (xdrs, &objp->prog))
                                 return FALSE;
                         if (!xdr_u_int (xdrs, &objp->vers))
                                 return FALSE;
                         if (!xdr_int (xdrs, &objp->proc))
                                 return FALSE;

                } else {
                (void)IXDR_PUT_U_INT32(buf, objp->prog);
                (void)IXDR_PUT_U_INT32(buf, objp->vers);
                (void)IXDR_PUT_INT32(buf, objp->proc);
                }
                 if (!xdr_virNetMessageType (xdrs, &objp->type))
                         return FALSE;
                 if (!xdr_u_int (xdrs, &objp->serial))
                         return FALSE;
                 if (!xdr_virNetMessageStatus (xdrs, &objp->status))
                         return FALSE;
                return TRUE;
        } else if (xdrs->x_op == XDR_DECODE) {
                buf = (int32_t*)XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
                if (buf == NULL) {
                         if (!xdr_u_int (xdrs, &objp->prog))
                                 return FALSE;
                         if (!xdr_u_int (xdrs, &objp->vers))
                                 return FALSE;
                         if (!xdr_int (xdrs, &objp->proc))
                                 return FALSE;

                } else {
                objp->prog = IXDR_GET_U_LONG(buf);
                objp->vers = IXDR_GET_U_LONG(buf);
                objp->proc = IXDR_GET_INT32(buf);
                }
                 if (!xdr_virNetMessageType (xdrs, &objp->type))
                         return FALSE;
                 if (!xdr_u_int (xdrs, &objp->serial))
                         return FALSE;
                 if (!xdr_virNetMessageStatus (xdrs, &objp->status))
                         return FALSE;
         return TRUE;
        }

         if (!xdr_u_int (xdrs, &objp->prog))
                 return FALSE;
         if (!xdr_u_int (xdrs, &objp->vers))
                 return FALSE;
         if (!xdr_int (xdrs, &objp->proc))
                 return FALSE;
         if (!xdr_virNetMessageType (xdrs, &objp->type))
                 return FALSE;
         if (!xdr_u_int (xdrs, &objp->serial))
                 return FALSE;
         if (!xdr_virNetMessageStatus (xdrs, &objp->status))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageUUID (XDR *xdrs, virNetMessageUUID objp)
{

         if (!xdr_opaque (xdrs, objp, VIR_UUID_BUFLEN))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageNonnullString (XDR *xdrs, virNetMessageNonnullString *objp)
{

         if (!xdr_string (xdrs, objp, VIR_NET_MESSAGE_STRING_MAX))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageString (XDR *xdrs, virNetMessageString *objp)
{

         if (!xdr_pointer (xdrs, (char **)objp, sizeof (virNetMessageNonnullString), (xdrproc_t) xdr_virNetMessageNonnullString))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageNonnullDomain (XDR *xdrs, virNetMessageNonnullDomain *objp)
{

         if (!xdr_virNetMessageNonnullString (xdrs, &objp->name))
                 return FALSE;
         if (!xdr_virNetMessageUUID (xdrs, objp->uuid))
                 return FALSE;
         if (!xdr_int (xdrs, &objp->id))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageNonnullNetwork (XDR *xdrs, virNetMessageNonnullNetwork *objp)
{

         if (!xdr_virNetMessageNonnullString (xdrs, &objp->name))
                 return FALSE;
         if (!xdr_virNetMessageUUID (xdrs, objp->uuid))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageDomain (XDR *xdrs, virNetMessageDomain *objp)
{

         if (!xdr_pointer (xdrs, (char **)objp, sizeof (virNetMessageNonnullDomain), (xdrproc_t) xdr_virNetMessageNonnullDomain))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageNetwork (XDR *xdrs, virNetMessageNetwork *objp)
{

         if (!xdr_pointer (xdrs, (char **)objp, sizeof (virNetMessageNonnullNetwork), (xdrproc_t) xdr_virNetMessageNonnullNetwork))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virNetMessageError (XDR *xdrs, virNetMessageError *objp)
{

         if (!xdr_int (xdrs, &objp->code))
                 return FALSE;
         if (!xdr_int (xdrs, &objp->domain))
                 return FALSE;
         if (!xdr_virNetMessageString (xdrs, &objp->message))
                 return FALSE;
         if (!xdr_int (xdrs, &objp->level))
                 return FALSE;
         if (!xdr_virNetMessageDomain (xdrs, &objp->dom))
                 return FALSE;
         if (!xdr_virNetMessageString (xdrs, &objp->str1))
                 return FALSE;
         if (!xdr_virNetMessageString (xdrs, &objp->str2))
                 return FALSE;
         if (!xdr_virNetMessageString (xdrs, &objp->str3))
                 return FALSE;
         if (!xdr_int (xdrs, &objp->int1))
                 return FALSE;
         if (!xdr_int (xdrs, &objp->int2))
                 return FALSE;
         if (!xdr_virNetMessageNetwork (xdrs, &objp->net))
                 return FALSE;
        return TRUE;
}
