/*
 * Compiler.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-040
 */

#ifndef HEADERS_COMPILER_H_
#define HEADERS_COMPILER_H_


#define DIO_MEM_CLASS
#define DIO_PTR_CLASS

#define AUTOMATIC
#define STATIC static
#define PTR_FAR

#define FUNC(returntype,memclass)                   returntype
#define VAR(vartype,memclass)                       vartype
#define P2FUNC(returntype,memclass,funcname)        returntype (* funcname)
#define CONST(consttype, memclass)                  const consttype
#define P2CONST(ptrtype,memclass,ptrclass)          const ptrtype *
#define P2VAR(ptrtype,memclass,ptrclass)            ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass)     ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass)   const ptrtype * const


#endif /* HEADERS_COMPILER_H_ */
