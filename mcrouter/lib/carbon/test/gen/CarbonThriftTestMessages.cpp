/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#include "CarbonThriftTestMessages.h"

namespace carbon {
namespace test {

constexpr const char* const DummyThriftRequest::name;

void DummyThriftRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(key_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testBool_ref(), fieldType);
        break;
      }
      case 3: {
        reader.readField(testInt8_ref(), fieldType);
        break;
      }
      case 4: {
        reader.readField(testInt16_ref(), fieldType);
        break;
      }
      case 5: {
        reader.readField(testInt32_ref(), fieldType);
        break;
      }
      case 6: {
        reader.readField(testInt64_ref(), fieldType);
        break;
      }
      case 7: {
        reader.readField(testUInt8_ref(), fieldType);
        break;
      }
      case 8: {
        reader.readField(testUInt16_ref(), fieldType);
        break;
      }
      case 9: {
        reader.readField(testUInt32_ref(), fieldType);
        break;
      }
      case 10: {
        reader.readField(testUInt64_ref(), fieldType);
        break;
      }
      case 11: {
        reader.readField(testFloat_ref(), fieldType);
        break;
      }
      case 12: {
        reader.readField(testDouble_ref(), fieldType);
        break;
      }
      case 13: {
        reader.readField(testShortString_ref(), fieldType);
        break;
      }
      case 14: {
        reader.readField(testLongString_ref(), fieldType);
        break;
      }
      case 15: {
        reader.readField(testIobuf_ref(), fieldType);
        break;
      }
      case 16: {
        reader.readField(testList_ref(), fieldType);
        break;
      }
      case 17: {
        reader.readField(testOptionalKeywordBool_ref(), fieldType);
        break;
      }
      case 18: {
        reader.readField(testOptionalKeywordString_ref(), fieldType);
        break;
      }
      case 19: {
        reader.readField(testOptionalKeywordIobuf_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void DummyThriftReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result_ref(), fieldType);
        break;
      }
      case 2: {
        reader.readField(message_ref(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}
} // namespace test
} // namespace carbon
