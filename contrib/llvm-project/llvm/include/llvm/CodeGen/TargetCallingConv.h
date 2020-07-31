//===-- llvm/CodeGen/TargetCallingConv.h - Calling Convention ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines types for working with calling-convention information.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CODEGEN_TARGETCALLINGCONV_H
#define LLVM_CODEGEN_TARGETCALLINGCONV_H

#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/Support/Alignment.h"
#include "llvm/Support/MachineValueType.h"
#include "llvm/Support/MathExtras.h"
#include <cassert>
#include <climits>
#include <cstdint>

namespace llvm {
namespace ISD {

  struct ArgFlagsTy {
  private:
    unsigned IsZExt : 1;     ///< Zero extended
    unsigned IsSExt : 1;     ///< Sign extended
    unsigned IsInReg : 1;    ///< Passed in register
    unsigned IsSRet : 1;     ///< Hidden struct-ret ptr
    unsigned IsByVal : 1;    ///< Struct passed by value
    unsigned IsNest : 1;     ///< Nested fn static chain
    unsigned IsReturned : 1; ///< Always returned
    unsigned IsSplit : 1;
    unsigned IsInAlloca : 1;   ///< Passed with inalloca
    unsigned IsPreallocated : 1; ///< ByVal without the copy
    unsigned IsSplitEnd : 1;   ///< Last part of a split
    unsigned IsSwiftSelf : 1;  ///< Swift self parameter
    unsigned IsSwiftError : 1; ///< Swift error parameter
    unsigned IsCFGuardTarget : 1; ///< Control Flow Guard target
    unsigned IsHva : 1;        ///< HVA field for
    unsigned IsHvaStart : 1;   ///< HVA structure start
    unsigned IsSecArgPass : 1; ///< Second argument
    unsigned ByValAlign : 4;   ///< Log 2 of byval alignment
    unsigned OrigAlign : 5;    ///< Log 2 of original alignment
    unsigned IsInConsecutiveRegsLast : 1;
    unsigned IsInConsecutiveRegs : 1;
    unsigned IsCopyElisionCandidate : 1; ///< Argument copy elision candidate
    unsigned IsPointer : 1;

    unsigned ByValSize; ///< Byval struct size

    unsigned PointerAddrSpace; ///< Address space of pointer argument

  public:
    ArgFlagsTy()
        : IsZExt(0), IsSExt(0), IsInReg(0), IsSRet(0), IsByVal(0), IsNest(0),
          IsReturned(0), IsSplit(0), IsInAlloca(0), IsPreallocated(0),
          IsSplitEnd(0), IsSwiftSelf(0), IsSwiftError(0), IsCFGuardTarget(0),
          IsHva(0), IsHvaStart(0), IsSecArgPass(0), ByValAlign(0), OrigAlign(0),
          IsInConsecutiveRegsLast(0), IsInConsecutiveRegs(0),
          IsCopyElisionCandidate(0), IsPointer(0), ByValSize(0),
          PointerAddrSpace(0) {
      static_assert(sizeof(*this) == 3 * sizeof(unsigned), "flags are too big");
    }

    bool isZExt() const { return IsZExt; }
    void setZExt() { IsZExt = 1; }

    bool isSExt() const { return IsSExt; }
    void setSExt() { IsSExt = 1; }

    bool isInReg() const { return IsInReg; }
    void setInReg() { IsInReg = 1; }

    bool isSRet() const { return IsSRet; }
    void setSRet() { IsSRet = 1; }

    bool isByVal() const { return IsByVal; }
    void setByVal() { IsByVal = 1; }

    bool isInAlloca() const { return IsInAlloca; }
    void setInAlloca() { IsInAlloca = 1; }

    bool isPreallocated() const { return IsPreallocated; }
    void setPreallocated() { IsPreallocated = 1; }

    bool isSwiftSelf() const { return IsSwiftSelf; }
    void setSwiftSelf() { IsSwiftSelf = 1; }

    bool isSwiftError() const { return IsSwiftError; }
    void setSwiftError() { IsSwiftError = 1; }

    bool isCFGuardTarget() const { return IsCFGuardTarget; }
    void setCFGuardTarget() { IsCFGuardTarget = 1; }

    bool isHva() const { return IsHva; }
    void setHva() { IsHva = 1; }

    bool isHvaStart() const { return IsHvaStart; }
    void setHvaStart() { IsHvaStart = 1; }

    bool isSecArgPass() const { return IsSecArgPass; }
    void setSecArgPass() { IsSecArgPass = 1; }

    bool isNest() const { return IsNest; }
    void setNest() { IsNest = 1; }

    bool isReturned() const { return IsReturned; }
    void setReturned() { IsReturned = 1; }

    bool isInConsecutiveRegs()  const { return IsInConsecutiveRegs; }
    void setInConsecutiveRegs() { IsInConsecutiveRegs = 1; }

    bool isInConsecutiveRegsLast() const { return IsInConsecutiveRegsLast; }
    void setInConsecutiveRegsLast() { IsInConsecutiveRegsLast = 1; }

    bool isSplit()   const { return IsSplit; }
    void setSplit()  { IsSplit = 1; }

    bool isSplitEnd()   const { return IsSplitEnd; }
    void setSplitEnd()  { IsSplitEnd = 1; }

    bool isCopyElisionCandidate()  const { return IsCopyElisionCandidate; }
    void setCopyElisionCandidate() { IsCopyElisionCandidate = 1; }

    bool isPointer()  const { return IsPointer; }
    void setPointer() { IsPointer = 1; }

    LLVM_ATTRIBUTE_DEPRECATED(unsigned getByValAlign() const,
                              "Use getNonZeroByValAlign() instead") {
      MaybeAlign A = decodeMaybeAlign(ByValAlign);
      return A ? A->value() : 0;
    }
    Align getNonZeroByValAlign() const {
      MaybeAlign A = decodeMaybeAlign(ByValAlign);
      assert(A && "ByValAlign must be defined");
      return *A;
    }
    void setByValAlign(Align A) {
      ByValAlign = encode(A);
      assert(getNonZeroByValAlign() == A && "bitfield overflow");
    }

    LLVM_ATTRIBUTE_DEPRECATED(unsigned getOrigAlign() const,
                              "Use getNonZeroOrigAlign() instead") {
      MaybeAlign A = decodeMaybeAlign(OrigAlign);
      return A ? A->value() : 0;
    }
    Align getNonZeroOrigAlign() const {
      return decodeMaybeAlign(OrigAlign).valueOrOne();
    }
    void setOrigAlign(Align A) {
      OrigAlign = encode(A);
      assert(getNonZeroOrigAlign() == A && "bitfield overflow");
    }

    unsigned getByValSize() const { return ByValSize; }
    void setByValSize(unsigned S) { ByValSize = S; }

    unsigned getPointerAddrSpace() const { return PointerAddrSpace; }
    void setPointerAddrSpace(unsigned AS) { PointerAddrSpace = AS; }
};

  /// InputArg - This struct carries flags and type information about a
  /// single incoming (formal) argument or incoming (from the perspective
  /// of the caller) return value virtual register.
  ///
  struct InputArg {
    ArgFlagsTy Flags;
    MVT VT = MVT::Other;
    EVT ArgVT;
    bool Used = false;

    /// Index original Function's argument.
    unsigned OrigArgIndex;
    /// Sentinel value for implicit machine-level input arguments.
    static const unsigned NoArgIndex = UINT_MAX;

    /// Offset in bytes of current input value relative to the beginning of
    /// original argument. E.g. if argument was splitted into four 32 bit
    /// registers, we got 4 InputArgs with PartOffsets 0, 4, 8 and 12.
    unsigned PartOffset;

    InputArg() = default;
    InputArg(ArgFlagsTy flags, EVT vt, EVT argvt, bool used,
             unsigned origIdx, unsigned partOffs)
      : Flags(flags), Used(used), OrigArgIndex(origIdx), PartOffset(partOffs) {
      VT = vt.getSimpleVT();
      ArgVT = argvt;
    }

    bool isOrigArg() const {
      return OrigArgIndex != NoArgIndex;
    }

    unsigned getOrigArgIndex() const {
      assert(OrigArgIndex != NoArgIndex && "Implicit machine-level argument");
      return OrigArgIndex;
    }
  };

  /// OutputArg - This struct carries flags and a value for a
  /// single outgoing (actual) argument or outgoing (from the perspective
  /// of the caller) return value virtual register.
  ///
  struct OutputArg {
    ArgFlagsTy Flags;
    MVT VT;
    EVT ArgVT;

    /// IsFixed - Is this a "fixed" value, ie not passed through a vararg "...".
    bool IsFixed = false;

    /// Index original Function's argument.
    unsigned OrigArgIndex;

    /// Offset in bytes of current output value relative to the beginning of
    /// original argument. E.g. if argument was splitted into four 32 bit
    /// registers, we got 4 OutputArgs with PartOffsets 0, 4, 8 and 12.
    unsigned PartOffset;

    OutputArg() = default;
    OutputArg(ArgFlagsTy flags, EVT vt, EVT argvt, bool isfixed,
              unsigned origIdx, unsigned partOffs)
      : Flags(flags), IsFixed(isfixed), OrigArgIndex(origIdx),
        PartOffset(partOffs) {
      VT = vt.getSimpleVT();
      ArgVT = argvt;
    }
  };

} // end namespace ISD
} // end namespace llvm

#endif // LLVM_CODEGEN_TARGETCALLINGCONV_H
