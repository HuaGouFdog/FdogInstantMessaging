/*
 Navicat Premium Data Transfer

 Source Server         : fdog
 Source Server Type    : MySQL
 Source Server Version : 50733
 Source Host           : localhost:3306
 Source Schema         : fdogsql

 Target Server Type    : MySQL
 Target Server Version : 50733
 File Encoding         : 65001

 Date: 16/06/2021 16:58:56
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for friend
-- ----------------------------
DROP TABLE IF EXISTS `friend`;
CREATE TABLE `friend`  (
  `characteristic` int(11) NOT NULL,
  `friendaccount` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `groupingid` int(11) NULL DEFAULT NULL,
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of friend
-- ----------------------------
INSERT INTO `friend` VALUES (2121, '19070015', 0, '12345678', '捂眼藏泪');
INSERT INTO `friend` VALUES (312, '54781204', 3, '12345678', '唯宠°');
INSERT INTO `friend` VALUES (432, '61673228', 1, '12345678', '何去何从i');
INSERT INTO `friend` VALUES (321, '12345678', 0, '61673228', '今夜无风');
INSERT INTO `friend` VALUES (32131, '12345678', 0, '19070015', '今夜无风');
INSERT INTO `friend` VALUES (123, '23101116', 0, '12345678', '帅癌晚期');
INSERT INTO `friend` VALUES (123, '12345678', 0, '23101116', '今夜无风');
INSERT INTO `friend` VALUES (123, '12345678', 0, '23101116', '今夜无风');
INSERT INTO `friend` VALUES (123, '12345678', 0, '23101116', '今夜无风');
INSERT INTO `friend` VALUES (123, '12345678', 0, '23101116', '今夜无风');

-- ----------------------------
-- Table structure for getverify
-- ----------------------------
DROP TABLE IF EXISTS `getverify`;
CREATE TABLE `getverify`  (
  `time` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `otheraccount` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `state` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `grouping` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of getverify
-- ----------------------------
INSERT INTO `getverify` VALUES ('今日', '23101116', '同意', '帅癌晚期', '三十年河东', '12345678');
INSERT INTO `getverify` VALUES ('今日', '12345678', '同意', '今夜无风', '我的好友', '23101116');
INSERT INTO `getverify` VALUES ('今日', '12345678', '同意', '今夜无风', '我的好友', '23101116');
INSERT INTO `getverify` VALUES ('今日', '12345678', '同意', '今夜无风', '我的好友', '23101116');
INSERT INTO `getverify` VALUES ('今日', '12345678', '同意', '今夜无风', '我的好友', '23101116');

-- ----------------------------
-- Table structure for grouping
-- ----------------------------
DROP TABLE IF EXISTS `grouping`;
CREATE TABLE `grouping`  (
  `groupingid` int(11) NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of grouping
-- ----------------------------
INSERT INTO `grouping` VALUES (0, '三十年河东', '12345678');
INSERT INTO `grouping` VALUES (1, '三十年河西', '12345678');
INSERT INTO `grouping` VALUES (2, '哪里需要三十年', '12345678');
INSERT INTO `grouping` VALUES (3, '三年就够了', '12345678');
INSERT INTO `grouping` VALUES (0, '我的好友', '61673228');
INSERT INTO `grouping` VALUES (0, '我的好友', '19070015');
INSERT INTO `grouping` VALUES (0, '我的好友', '23101116');

-- ----------------------------
-- Table structure for setverify
-- ----------------------------
DROP TABLE IF EXISTS `setverify`;
CREATE TABLE `setverify`  (
  `time` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `state` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `grouping` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `otheraccount` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of setverify
-- ----------------------------
INSERT INTO `setverify` VALUES ('06.01', '23101116', '同意', '今夜无风', '我的好友', '12345678');
INSERT INTO `setverify` VALUES ('06.01', '12345678', '等待同意', '帅癌晚期', '三十年河东', '23101116');
INSERT INTO `setverify` VALUES ('06.01', '12345678', '等待同意', '帅癌晚期', '三十年河东', '23101116');
INSERT INTO `setverify` VALUES ('06.01', '12345678', '等待同意', '帅癌晚期', '三十年河东', '23101116');
INSERT INTO `setverify` VALUES ('06.01', '12345678', '等待同意', '帅癌晚期', '三十年河东', '23101116');

-- ----------------------------
-- Table structure for state
-- ----------------------------
DROP TABLE IF EXISTS `state`;
CREATE TABLE `state`  (
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `isline` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `ip` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `port` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`account`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of state
-- ----------------------------
INSERT INTO `state` VALUES ('12345678', '-1', '10.13.130.101', '0');
INSERT INTO `state` VALUES ('19070015', '-1', '10.12.135.133', '0');
INSERT INTO `state` VALUES ('23101116', '-1', '10.12.135.133', '0');
INSERT INTO `state` VALUES ('61673228', '-1', '10.13.130.101', '0');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `account` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `phone` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `signature` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `url` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `grade` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `namet` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sex` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `age` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `birthday` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `profession` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`account`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('12345678', '18082069862', '今夜无风', '3226960*', '吾今虽欲自以为不足，而众已妄推之矣。', 'https://www.fdogcsdn.cn/img/10001.jpg', '12', '张旭', '男', '21', '2000.03.31', 'IT计算机服务');
INSERT INTO `user` VALUES ('19070015', '13081522051', '捂眼藏泪', '123456', '不喝酒，不抽烟，三年省下无数钱。', 'https://www.fdogcsdn.cn/img/19070015.jpg', '13', '朱盛泽', '男', '20', '2000.08.12', '学生');
INSERT INTO `user` VALUES ('23101116', '17614744373', '帅癌晚期', '3226960*', '葡萄美酒夜光杯，欲饮琵琶马上催。醉卧沙场君莫笑，古来征战几人回?', 'https://www.fdogcsdn.cn/img/23101116.jpg', '43', '王菲', '女', '18', '2001.03.10', '会计');
INSERT INTO `user` VALUES ('54781204', '17614733828', '唯宠°', '12334455', '我不喜欢喝酒，我只是买醉。', 'https://www.fdogcsdn.cn/img/54781204.jpg', '132', '于静', '女', '20', '1999.03.12', '教师');
INSERT INTO `user` VALUES ('61673228', '15647649853', '何去何从i', 'wjq123456', '每天的一个人的世界。只有自己一个人才是最真实的。一个人抽烟，一个人喝酒。', 'https://www.fdogcsdn.cn/img/61673228.jpg', '65', '王景奇', '男', '21', '2000.05.07', 'IT计算机服务');

SET FOREIGN_KEY_CHECKS = 1;
