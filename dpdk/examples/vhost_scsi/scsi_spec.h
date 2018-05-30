/*-
 *   BSD LICENSE
 *
 *   Copyright (c) Intel Corporation.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * SCSI specification definition
 * refer http://www.t10.org/drafts.htm#SPC_Family for SPC-3 and SBC-3
 */

#ifndef _SCSI_SPEC_H
#define _SCSI_SPEC_H

#include <stdint.h>

enum scsi_group_code {
	SCSI_6BYTE_CMD = 0x00,
	SCSI_10BYTE_CMD = 0x20,
	SCSI_10BYTE_CMD2 = 0x40,
	SCSI_16BYTE_CMD = 0x80,
	SCSI_12BYTE_CMD = 0xa0,
};

#define SCSI_GROUP_MASK	0xe0
#define SCSI_OPCODE_MASK	0x1f

enum scsi_status {
	SCSI_STATUS_GOOD = 0x00,
	SCSI_STATUS_CHECK_CONDITION = 0x02,
	SCSI_STATUS_CONDITION_MET = 0x04,
	SCSI_STATUS_BUSY = 0x08,
	SCSI_STATUS_INTERMEDIATE = 0x10,
	SCSI_STATUS_INTERMEDIATE_CONDITION_MET = 0x14,
	SCSI_STATUS_RESERVATION_CONFLICT = 0x18,
	SCSI_STATUS_Obsolete = 0x22,
	SCSI_STATUS_TASK_SET_FULL = 0x28,
	SCSI_STATUS_ACA_ACTIVE = 0x30,
	SCSI_STATUS_TASK_ABORTED = 0x40,
};

enum scsi_sense {
	SCSI_SENSE_NO_SENSE = 0x00,
	SCSI_SENSE_RECOVERED_ERROR = 0x01,
	SCSI_SENSE_NOT_READY = 0x02,
	SCSI_SENSE_MEDIUM_ERROR = 0x03,
	SCSI_SENSE_HARDWARE_ERROR = 0x04,
	SCSI_SENSE_ILLEGAL_REQUEST = 0x05,
	SCSI_SENSE_UNIT_ATTENTION = 0x06,
	SCSI_SENSE_DATA_PROTECT = 0x07,
	SCSI_SENSE_BLANK_CHECK = 0x08,
	SCSI_SENSE_VENDOR_SPECIFIC = 0x09,
	SCSI_SENSE_COPY_ABORTED = 0x0a,
	SCSI_SENSE_ABORTED_COMMAND = 0x0b,
	SCSI_SENSE_VOLUME_OVERFLOW = 0x0d,
	SCSI_SENSE_MISCOMPARE = 0x0e,
};

enum scsi_asc {
	SCSI_ASC_NO_ADDITIONAL_SENSE = 0x00,
	SCSI_ASC_PERIPHERAL_DEVICE_WRITE_FAULT = 0x03,
	SCSI_ASC_LOGICAL_UNIT_NOT_READY = 0x04,
	SCSI_ASC_WARNING = 0x0b,
	SCSI_ASC_LOGICAL_BLOCK_GUARD_CHECK_FAILED = 0x10,
	SCSI_ASC_LOGICAL_BLOCK_APP_TAG_CHECK_FAILED = 0x10,
	SCSI_ASC_LOGICAL_BLOCK_REF_TAG_CHECK_FAILED = 0x10,
	SCSI_ASC_UNRECOVERED_READ_ERROR = 0x11,
	SCSI_ASC_MISCOMPARE_DURING_VERIFY_OPERATION = 0x1d,
	SCSI_ASC_INVALID_COMMAND_OPERATION_CODE = 0x20,
	SCSI_ASC_ACCESS_DENIED = 0x20,
	SCSI_ASC_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE = 0x21,
	SCSI_ASC_INVALID_FIELD_IN_CDB = 0x24,
	SCSI_ASC_LOGICAL_UNIT_NOT_SUPPORTED = 0x25,
	SCSI_ASC_WRITE_PROTECTED = 0x27,
	SCSI_ASC_FORMAT_COMMAND_FAILED = 0x31,
	SCSI_ASC_INTERNAL_TARGET_FAILURE = 0x44,
};

enum scsi_ascq {
	SCSI_ASCQ_CAUSE_NOT_REPORTABLE = 0x00,
	SCSI_ASCQ_BECOMING_READY = 0x01,
	SCSI_ASCQ_FORMAT_COMMAND_FAILED = 0x01,
	SCSI_ASCQ_LOGICAL_BLOCK_GUARD_CHECK_FAILED = 0x01,
	SCSI_ASCQ_LOGICAL_BLOCK_APP_TAG_CHECK_FAILED = 0x02,
	SCSI_ASCQ_NO_ACCESS_RIGHTS = 0x02,
	SCSI_ASCQ_LOGICAL_BLOCK_REF_TAG_CHECK_FAILED = 0x03,
	SCSI_ASCQ_POWER_LOSS_EXPECTED = 0x08,
	SCSI_ASCQ_INVALID_LU_IDENTIFIER = 0x09,
};

enum spc_opcode {
	/* SPC3 related */
	SPC_ACCESS_CONTROL_IN = 0x86,
	SPC_ACCESS_CONTROL_OUT = 0x87,
	SPC_EXTENDED_COPY = 0x83,
	SPC_INQUIRY = 0x12,
	SPC_LOG_SELECT = 0x4c,
	SPC_LOG_SENSE = 0x4d,
	SPC_MODE_SELECT_6 = 0x15,
	SPC_MODE_SELECT_10 = 0x55,
	SPC_MODE_SENSE_6 = 0x1a,
	SPC_MODE_SENSE_10 = 0x5a,
	SPC_PERSISTENT_RESERVE_IN = 0x5e,
	SPC_PERSISTENT_RESERVE_OUT = 0x5f,
	SPC_PREVENT_ALLOW_MEDIUM_REMOVAL = 0x1e,
	SPC_READ_ATTRIBUTE = 0x8c,
	SPC_READ_BUFFER = 0x3c,
	SPC_RECEIVE_COPY_RESULTS = 0x84,
	SPC_RECEIVE_DIAGNOSTIC_RESULTS = 0x1c,
	SPC_REPORT_LUNS = 0xa0,
	SPC_REQUEST_SENSE = 0x03,
	SPC_SEND_DIAGNOSTIC = 0x1d,
	SPC_TEST_UNIT_READY = 0x00,
	SPC_WRITE_ATTRIBUTE = 0x8d,
	SPC_WRITE_BUFFER = 0x3b,

	SPC_SERVICE_ACTION_IN_12 = 0xab,
	SPC_SERVICE_ACTION_OUT_12 = 0xa9,
	SPC_SERVICE_ACTION_IN_16 = 0x9e,
	SPC_SERVICE_ACTION_OUT_16 = 0x9f,

	SPC_VARIABLE_LENGTH = 0x7f,

	SPC_MO_CHANGE_ALIASES = 0x0b,
	SPC_MO_SET_DEVICE_IDENTIFIER = 0x06,
	SPC_MO_SET_PRIORITY = 0x0e,
	SPC_MO_SET_TARGET_PORT_GROUPS = 0x0a,
	SPC_MO_SET_TIMESTAMP = 0x0f,
	SPC_MI_REPORT_ALIASES = 0x0b,
	SPC_MI_REPORT_DEVICE_IDENTIFIER = 0x05,
	SPC_MI_REPORT_PRIORITY = 0x0e,
	SPC_MI_REPORT_SUPPORTED_OPERATION_CODES = 0x0c,
	SPC_MI_REPORT_SUPPORTED_TASK_MANAGEMENT_FUNCTIONS = 0x0d,
	SPC_MI_REPORT_TARGET_PORT_GROUPS = 0x0a,
	SPC_MI_REPORT_TIMESTAMP = 0x0f,

	/* SPC2 related (Obsolete) */
	SPC2_RELEASE_6 = 0x17,
	SPC2_RELEASE_10 = 0x57,
	SPC2_RESERVE_6 = 0x16,
	SPC2_RESERVE_10 = 0x56,
};

enum scc_opcode {
	SCC_MAINTENANCE_IN = 0xa3,
	SCC_MAINTENANCE_OUT = 0xa4,
};

enum sbc_opcode {
	SBC_COMPARE_AND_WRITE = 0x89,
	SBC_FORMAT_UNIT = 0x04,
	SBC_GET_LBA_STATUS = 0x0012009e,
	SBC_ORWRITE_16 = 0x8b,
	SBC_PRE_FETCH_10 = 0x34,
	SBC_PRE_FETCH_16 = 0x90,
	SBC_READ_6 = 0x08,
	SBC_READ_10 = 0x28,
	SBC_READ_12 = 0xa8,
	SBC_READ_16 = 0x88,
	SBC_READ_ATTRIBUTE = 0x8c,
	SBC_READ_BUFFER = 0x3c,
	SBC_READ_CAPACITY_10 = 0x25,
	SBC_READ_DEFECT_DATA_10 = 0x37,
	SBC_READ_DEFECT_DATA_12 = 0xb7,
	SBC_READ_LONG_10 = 0x3e,
	SBC_REASSIGN_BLOCKS = 0x07,
	SBC_SANITIZE = 0x48,
	SBC_START_STOP_UNIT = 0x1b,
	SBC_SYNCHRONIZE_CACHE_10 = 0x35,
	SBC_SYNCHRONIZE_CACHE_16 = 0x91,
	SBC_UNMAP = 0x42,
	SBC_VERIFY_10 = 0x2f,
	SBC_VERIFY_12 = 0xaf,
	SBC_VERIFY_16 = 0x8f,
	SBC_WRITE_6 = 0x0a,
	SBC_WRITE_10 = 0x2a,
	SBC_WRITE_12 = 0xaa,
	SBC_WRITE_16 = 0x8a,
	SBC_WRITE_AND_VERIFY_10 = 0x2e,
	SBC_WRITE_AND_VERIFY_12 = 0xae,
	SBC_WRITE_AND_VERIFY_16 = 0x8e,
	SBC_WRITE_LONG_10 = 0x3f,
	SBC_WRITE_SAME_10 = 0x41,
	SBC_WRITE_SAME_16 = 0x93,
	SBC_XDREAD_10 = 0x52,
	SBC_XDWRITE_10 = 0x50,
	SBC_XDWRITEREAD_10 = 0x53,
	SBC_XPWRITE_10 = 0x51,

	SBC_SAI_READ_CAPACITY_16 = 0x10,
	SBC_SAI_READ_LONG_16 = 0x11,
	SBC_SAO_WRITE_LONG_16 = 0x11,

	SBC_VL_READ_32 = 0x0009,
	SBC_VL_VERIFY_32 = 0x000a,
	SBC_VL_WRITE_32 = 0x000b,
	SBC_VL_WRITE_AND_VERIFY_32 = 0x000c,
	SBC_VL_WRITE_SAME_32 = 0x000d,
	SBC_VL_XDREAD_32 = 0x0003,
	SBC_VL_XDWRITE_32 = 0x0004,
	SBC_VL_XDWRITEREAD_32 = 0x0007,
	SBC_VL_XPWRITE_32 = 0x0006,
};

enum mmc_opcode {
	/* MMC6 */
	MMC_READ_DISC_STRUCTURE = 0xad,

	/* MMC4 */
	MMC_BLANK = 0xa1,
	MMC_CLOSE_TRACK_SESSION = 0x5b,
	MMC_ERASE_10 = 0x2c,
	MMC_FORMAT_UNIT = 0x04,
	MMC_GET_CONFIGURATION = 0x46,
	MMC_GET_EVENT_STATUS_NOTIFICATION = 0x4a,
	MMC_GET_PERFORMANCE = 0xac,
	MMC_INQUIRY = 0x12,
	MMC_LOAD_UNLOAD_MEDIUM = 0xa6,
	MMC_MECHANISM_STATUS = 0xbd,
	MMC_MODE_SELECT_10 = 0x55,
	MMC_MODE_SENSE_10 = 0x5a,
	MMC_PAUSE_RESUME = 0x4b,
	MMC_PLAY_AUDIO_10 = 0x45,
	MMC_PLAY_AUDIO_12 = 0xa5,
	MMC_PLAY_AUDIO_MSF = 0x47,
	MMC_PREVENT_ALLOW_MEDIUM_REMOVAL = 0x1e,
	MMC_READ_10 = 0x28,
	MMC_READ_12 = 0xa8,
	MMC_READ_BUFFER = 0x3c,
	MMC_READ_BUFFER_CAPACITY = 0x5c,
	MMC_READ_CAPACITY = 0x25,
	MMC_READ_CD = 0xbe,
	MMC_READ_CD_MSF = 0xb9,
	MMC_READ_DISC_INFORMATION = 0x51,
	MMC_READ_DVD_STRUCTURE = 0xad,
	MMC_READ_FORMAT_CAPACITIES = 0x23,
	MMC_READ_SUB_CHANNEL = 0x42,
	MMC_READ_TOC_PMA_ATIP = 0x43,
	MMC_READ_TRACK_INFORMATION = 0x52,
	MMC_REPAIR_TRACK = 0x58,
	MMC_REPORT_KEY = 0xa4,
	MMC_REQUEST_SENSE = 0x03,
	MMC_RESERVE_TRACK = 0x53,
	MMC_SCAN = 0xba,
	MMC_SEEK_10 = 0x2b,
	MMC_SEND_CUE_SHEET = 0x5d,
	MMC_SEND_DVD_STRUCTURE = 0xbf,
	MMC_SEND_KEY = 0xa3,
	MMC_SEND_OPC_INFORMATION = 0x54,
	MMC_SET_CD_SPEED = 0xbb,
	MMC_SET_READ_AHEAD = 0xa7,
	MMC_SET_STREAMING = 0xb6,
	MMC_START_STOP_UNIT = 0x1b,
	MMC_STOP_PLAY_SCAN = 0x4e,
	MMC_SYNCHRONIZE_CACHE = 0x35,
	MMC_TEST_UNIT_READY = 0x00,
	MMC_VERIFY_10 = 0x2f,
	MMC_WRITE_10 = 0xa2,
	MMC_WRITE_12 = 0xaa,
	MMC_WRITE_AND_VERIFY_10 = 0x2e,
	MMC_WRITE_BUFFER = 0x3b,
};

enum ssc_opcode {
	SSC_ERASE_6 = 0x19,
	SSC_FORMAT_MEDIUM = 0x04,
	SSC_LOAD_UNLOAD = 0x1b,
	SSC_LOCATE_10 = 0x2b,
	SSC_LOCATE_16 = 0x92,
	SSC_MOVE_MEDIUM_ATTACHED = 0xa7,
	SSC_READ_6 = 0x08,
	SSC_READ_BLOCK_LIMITS = 0x05,
	SSC_READ_ELEMENT_STATUS_ATTACHED = 0xb4,
	SSC_READ_POSITION = 0x34,
	SSC_READ_REVERSE_6 = 0x0f,
	SSC_RECOVER_BUFFERED_DATA = 0x14,
	SSC_REPORT_DENSITY_SUPPORT = 0x44,
	SSC_REWIND = 0x01,
	SSC_SET_CAPACITY = 0x0b,
	SSC_SPACE_6 = 0x11,
	SSC_SPACE_16 = 0x91,
	SSC_VERIFY_6 = 0x13,
	SSC_WRITE_6 = 0x0a,
	SSC_WRITE_FILEMARKS_6 = 0x10,
};

enum spc_vpd {
	SPC_VPD_DEVICE_IDENTIFICATION = 0x83,
	SPC_VPD_EXTENDED_INQUIRY_DATA = 0x86,
	SPC_VPD_MANAGEMENT_NETWORK_ADDRESSES = 0x85,
	SPC_VPD_MODE_PAGE_POLICY = 0x87,
	SPC_VPD_SCSI_PORTS = 0x88,
	SPC_VPD_SOFTWARE_INTERFACE_IDENTIFICATION = 0x84,
	SPC_VPD_SUPPORTED_VPD_PAGES = 0x00,
	SPC_VPD_UNIT_SERIAL_NUMBER = 0x80,
	SPC_VPD_BLOCK_LIMITS = 0xb0,
	SPC_VPD_BLOCK_DEV_CHARS = 0xb1,
	SPC_VPD_BLOCK_THIN_PROVISION = 0xb2,
};

enum {
	SPC_PERIPHERAL_DEVICE_TYPE_DISK = 0x00,
	SPC_PERIPHERAL_DEVICE_TYPE_TAPE = 0x01,
	SPC_PERIPHERAL_DEVICE_TYPE_DVD = 0x05,
	SPC_PERIPHERAL_DEVICE_TYPE_CHANGER = 0x08,

	SPC_VERSION_NONE = 0x00,
	SPC_VERSION_SPC = 0x03,
	SPC_VERSION_SPC2 = 0x04,
	SPC_VERSION_SPC3 = 0x05,
	SPC_VERSION_SPC4 = 0x06,

	SPC_PROTOCOL_IDENTIFIER_FC = 0x00,
	SPC_PROTOCOL_IDENTIFIER_PSCSI = 0x01,
	SPC_PROTOCOL_IDENTIFIER_SSA = 0x02,
	SPC_PROTOCOL_IDENTIFIER_IEEE1394 = 0x03,
	SPC_PROTOCOL_IDENTIFIER_RDMA = 0x04,
	SPC_PROTOCOL_IDENTIFIER_ISCSI = 0x05,
	SPC_PROTOCOL_IDENTIFIER_SAS = 0x06,
	SPC_PROTOCOL_IDENTIFIER_ADT = 0x07,
	SPC_PROTOCOL_IDENTIFIER_ATA = 0x08,

	SPC_VPD_CODE_SET_BINARY = 0x01,
	SPC_VPD_CODE_SET_ASCII = 0x02,
	SPC_VPD_CODE_SET_UTF8 = 0x03,

	SPC_VPD_ASSOCIATION_LOGICAL_UNIT = 0x00,
	SPC_VPD_ASSOCIATION_TARGET_PORT = 0x01,
	SPC_VPD_ASSOCIATION_TARGET_DEVICE = 0x02,

	SPC_VPD_IDENTIFIER_TYPE_VENDOR_SPECIFIC = 0x00,
	SPC_VPD_IDENTIFIER_TYPE_T10_VENDOR_ID = 0x01,
	SPC_VPD_IDENTIFIER_TYPE_EUI64 = 0x02,
	SPC_VPD_IDENTIFIER_TYPE_NAA = 0x03,
	SPC_VPD_IDENTIFIER_TYPE_RELATIVE_TARGET_PORT = 0x04,
	SPC_VPD_IDENTIFIER_TYPE_TARGET_PORT_GROUP = 0x05,
	SPC_VPD_IDENTIFIER_TYPE_LOGICAL_UNIT_GROUP = 0x06,
	SPC_VPD_IDENTIFIER_TYPE_MD5_LOGICAL_UNIT = 0x07,
	SPC_VPD_IDENTIFIER_TYPE_SCSI_NAME = 0x08,
};

struct scsi_cdb_inquiry {
	uint8_t opcode;
	uint8_t evpd;
	uint8_t page_code;
	uint16_t alloc_len;
	uint8_t control;
};

struct scsi_cdb_inquiry_data {
	uint8_t peripheral;
	uint8_t rmb;
	uint8_t version;
	uint8_t response;
	uint8_t add_len;
	uint8_t flags;
	uint8_t flags2;
	uint8_t flags3;
	uint8_t t10_vendor_id[8];
	uint8_t product_id[16];
	uint8_t product_rev[4];
	uint8_t vendor[20];
	uint8_t ius;
	uint8_t reserved;
	uint8_t desc[];
};

struct scsi_vpd_page {
	uint8_t peripheral;
	uint8_t page_code;
	uint16_t alloc_len;
	uint8_t params[];
};

#define SCSI_VEXT_REF_CHK		0x01
#define SCSI_VEXT_APP_CHK		0x02
#define SCSI_VEXT_GRD_CHK		0x04
#define SCSI_VEXT_SIMPSUP		0x01
#define SCSI_VEXT_ORDSUP		0x02
#define SCSI_VEXT_HEADSUP		0x04
#define SCSI_VEXT_PRIOR_SUP	0x08
#define SCSI_VEXT_GROUP_SUP	0x10
#define SCSI_VEXT_UASK_SUP		0x20
#define SCSI_VEXT_V_SUP		0x01
#define SCSI_VEXT_NV_SUP		0x02
#define SCSI_VEXT_CRD_SUP		0x04
#define SCSI_VEXT_WU_SUP		0x08

struct scsi_vpd_ext_inquiry {
	uint8_t peripheral;
	uint8_t page_code;
	uint16_t alloc_len;
	uint8_t check;
	uint8_t sup;
	uint8_t sup2;
	uint8_t luiclr;
	uint8_t cbcs;
	uint8_t micro_dl;
	uint8_t reserved[54];
};

#define SPC_VPD_DESIG_PIV	0x80

/* designation descriptor */
struct scsi_desig_desc {
	uint8_t code_set	: 4;
	uint8_t protocol_id	: 4;
	uint8_t type		: 4;
	uint8_t association	: 2;
	uint8_t reserved0	: 1;
	uint8_t piv		: 1;
	uint8_t reserved1;
	uint8_t	len;
	uint8_t desig[];
};

/* mode page policy descriptor */
struct scsi_mpage_policy_desc {
	uint8_t page_code;
	uint8_t sub_page_code;
	uint8_t policy;
	uint8_t reserved;
};

/* target port descriptor */
struct scsi_tgt_port_desc {
	uint8_t code_set;
	uint8_t desig_type;
	uint8_t reserved;
	uint8_t	len;
	uint8_t designator[];
};

/* SCSI port designation descriptor */
struct scsi_port_desc {
	uint16_t reserved;
	uint16_t rel_port_id;
	uint16_t reserved2;
	uint16_t init_port_len;
	uint16_t init_port_id;
	uint16_t reserved3;
	uint16_t tgt_desc_len;
	uint8_t tgt_desc[];
};

/* SCSI UNMAP block descriptor */
struct scsi_unmap_bdesc {
	/* UNMAP LOGICAL BLOCK ADDRESS */
	uint64_t lba;

	/* NUMBER OF LOGICAL BLOCKS */
	uint32_t block_count;

	/* RESERVED */
	uint32_t reserved;
};

#define SCSI_UNMAP_LBPU				(1 << 7)
#define SCSI_UNMAP_LBPWS			(1 << 6)
#define SCSI_UNMAP_LBPWS10			(1 << 5)

#define SCSI_UNMAP_FULL_PROVISIONING	0x00
#define SCSI_UNMAP_RESOURCE_PROVISIONING	0x01
#define SCSI_UNMAP_THIN_PROVISIONING	0x02

#endif /* _SCSI_SPEC_H */