/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_web_protocol_http_incoming_SimpleBodyDecoder_hpp
#define oatpp_web_protocol_http_incoming_SimpleBodyDecoder_hpp

#include "BodyDecoder.hpp"
#include "oatpp/web/protocol/http/encoding/EncoderCollection.hpp"

namespace oatpp { namespace web { namespace protocol { namespace http { namespace incoming {

/**
 * Default implementation of &id:oatpp::web::protocol::http::incoming::BodyDecoder;.
 */
class SimpleBodyDecoder : public BodyDecoder {
private:
  std::shared_ptr<encoding::EncoderCollection> m_contentDecoders;
private:
  std::shared_ptr<data::buffer::Processor> getStreamProcessor(const data::share::StringKeyLabelCI& transferEncoding,
                                                              const data::share::StringKeyLabelCI& contentEncoding) const;
public:

  /**
   * Constructor.
   * @param decoders - collection content decoders.
   */
  SimpleBodyDecoder(const std::shared_ptr<encoding::EncoderCollection>& contentDecoders);

  /**
   * Decode bodyStream and write decoded data to toStream.
   * @param headers - Headers map. &id:oatpp::web::protocol::http::Headers;.
   * @param bodyStream - pointer to &id:oatpp::data::stream::InputStream;.
   * @param writeCallback - &id:oatpp::data::stream::WriteCallback;.
   */
  void decode(const Headers& headers, data::stream::InputStream* bodyStream, data::stream::WriteCallback* writeCallback) const override;

  /**
   * Same as &l:SimpleBodyDecoder::decode (); but Async.
   * @param headers - Headers map. &id:oatpp::web::protocol::http::Headers;.
   * @param bodyStream - `std::shared_ptr` to &id:oatpp::data::stream::InputStream;.
   * @param writeCallback - `std::shared_ptr` to &id:oatpp::data::stream::WriteCallback;.
   * @return - &id:oatpp::async::CoroutineStarter;.
   */
  oatpp::async::CoroutineStarter decodeAsync(const Headers& headers,
                                             const std::shared_ptr<oatpp::data::stream::InputStream>& bodyStream,
                                             const std::shared_ptr<oatpp::data::stream::WriteCallback>& writeCallback) const override;
  
  
};
  
}}}}}

#endif /* oatpp_web_protocol_http_incoming_SimpleBodyDecoder_hpp */
