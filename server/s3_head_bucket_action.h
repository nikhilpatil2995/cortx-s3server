/*
 * COPYRIGHT 2015 SEAGATE LLC
 *
 * THIS DRAWING/DOCUMENT, ITS SPECIFICATIONS, AND THE DATA CONTAINED
 * HEREIN, ARE THE EXCLUSIVE PROPERTY OF SEAGATE TECHNOLOGY
 * LIMITED, ISSUED IN STRICT CONFIDENCE AND SHALL NOT, WITHOUT
 * THE PRIOR WRITTEN PERMISSION OF SEAGATE TECHNOLOGY LIMITED,
 * BE REPRODUCED, COPIED, OR DISCLOSED TO A THIRD PARTY, OR
 * USED FOR ANY PURPOSE WHATSOEVER, OR STORED IN A RETRIEVAL SYSTEM
 * EXCEPT AS ALLOWED BY THE TERMS OF SEAGATE LICENSES AND AGREEMENTS.
 *
 * YOU SHOULD HAVE RECEIVED A COPY OF SEAGATE'S LICENSE ALONG WITH
 * THIS RELEASE. IF NOT PLEASE CONTACT A SEAGATE REPRESENTATIVE
 * http://www.seagate.com/contact
 *
 * Original author:  Kaustubh Deorukhkar   <kaustubh.deorukhkar@seagate.com>
 * Original creation date: 1-Oct-2015
 */

#pragma once

#ifndef __S3_SERVER_S3_HEAD_BUCKET_ACTION_H__
#define __S3_SERVER_S3_HEAD_BUCKET_ACTION_H__

#include "s3_action_base.h"
#include "s3_bucket_metadata.h"
#include "s3_factory.h"

class S3HeadBucketAction : public S3Action {
  std::shared_ptr<S3BucketMetadata> bucket_metadata;
  std::shared_ptr<S3BucketMetadataFactory> bucket_metadata_factory;

 public:
  S3HeadBucketAction(
      std::shared_ptr<S3RequestObject> req,
      std::shared_ptr<S3BucketMetadataFactory> bucket_meta_factory = nullptr);

  void setup_steps();
  void read_metadata();
  void send_response_to_s3_client();

  // For Testing purpose
  FRIEND_TEST(S3HeadBucketActionTest, Constructor);
  FRIEND_TEST(S3HeadBucketActionTest, ReadMetaData);
  FRIEND_TEST(S3HeadBucketActionTest, SendResponseToClientServiceUnavailable);
  FRIEND_TEST(S3HeadBucketActionTest, SendResponseToClientNoSuchBucket);
  FRIEND_TEST(S3HeadBucketActionTest, SendResponseToClientInternalError);
  FRIEND_TEST(S3HeadBucketActionTest, SendResponseToClientSuccess);
};

#endif
