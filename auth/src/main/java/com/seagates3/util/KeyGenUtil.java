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
 * Original author:  Arjun Hariharan <arjun.hariharan@seagate.com>
 * Original creation date: 17-Sep-2014
 */

package com.seagates3.util;

public class KeyGenUtil {
    /*
     * To do
     * UserId and userAccessKeyIds are generated from uuid encoding it to base 64.
     * Replace it with a better approach in the next release.
     */

    /*
     * Generate a new user Id.
     */
    public static String userId() {
        return BinaryUtil.base64UUID().substring(0, 22);
    }

    /*
     * Generate a new Access Key Id for the user.
     *
     * To do
     * Since the Access Key Id is generated by encoding uuid to Base 64,
     * the length equals to 22 characters while AWS access key Ids are 20 characters.
     * Improve the Access Key generator to generate 20 character long access key id.
     * The access key id can be generated based on geogrphical location or other
     * parameters.
     */
    public static String userAccessKeyId() {
        return BinaryUtil.base64UUID().substring(0, 22);
    }

    /*
     * Generate a secret key for the user.
     */
    public static String userSercretKey(String strToEncode) {
        String secret_key = BinaryUtil.base64EncodedHash(strToEncode);
        return secret_key.substring(0,40);
    }

    /*
     * Generate a new session Id for the temporary user (federated user).
     */
    public static String sessionId(String strToEncode) {
        return BinaryUtil.base64EncodedHash(strToEncode);
    }
}
