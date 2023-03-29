// ======================================================================
// \title  TestComponent/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for TestComponent component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
//
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ======================================================================

#ifndef TestComponent_GTEST_BASE_HPP
#define TestComponent_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_testOut_SIZE(size) \
  this->assert_from_testOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_testOut(index, _arg1, _arg2, _arg3) \
  { \
    ASSERT_GT(this->fromPortHistory_testOut->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_testOut\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_testOut->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_testOut& _e = \
      this->fromPortHistory_testOut->at(index); \
    ASSERT_EQ(_arg1, _e.arg1) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument arg1 at index " \
    << index \
    << " in history of from_testOut\n" \
    << "  Expected: " << _arg1 << "\n" \
    << "  Actual:   " << _e.arg1 << "\n"; \
    ASSERT_EQ(_arg2, _e.arg2) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument arg2 at index " \
    << index \
    << " in history of from_testOut\n" \
    << "  Expected: " << _arg2 << "\n" \
    << "  Actual:   " << _e.arg2 << "\n"; \
    ASSERT_EQ(_arg3, _e.arg3) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument arg3 at index " \
    << index \
    << " in history of from_testOut\n" \
    << "  Expected: " << _arg3 << "\n" \
    << "  Actual:   " << _e.arg3 << "\n"; \
  }

namespace ExampleComponents {

  //! \class TestComponentGTestBase
  //! \brief Auto-generated base class for TestComponent component Google Test harness
  //!
  class TestComponentGTestBase :
    public TestComponentTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object TestComponentGTestBase
      //!
      TestComponentGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, //!< The component name
          const U32 maxHistorySize //!< The maximum size of each history
#else
          const U32 maxHistorySize //!< The maximum size of each history
#endif
      );

      //! Destroy object TestComponentGTestBase
      //!
      virtual ~TestComponentGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // From ports 
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __ISF_callSiteFileName, //!< The name of the file containing the call site
          const U32 __ISF_callSiteLineNumber, //!< The line number of the call site
          const U32 size //!< The asserted size
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: testOut 
      // ----------------------------------------------------------------------

      void assert_from_testOut_size(
          const char *const __ISF_callSiteFileName, //!< The name of the file containing the call site
          const U32 __ISF_callSiteLineNumber, //!< The line number of the call site
          const U32 size //!< The asserted size
      ) const;

  };

} // end namespace ExampleComponents

#endif
