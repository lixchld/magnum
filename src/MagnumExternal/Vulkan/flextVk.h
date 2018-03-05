#ifndef _flextvk_h_
#define _flextvk_h_
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#include <cstdint>
#include <Corrade/Utility/VisibilityMacros.h>

#include "Magnum/configure.h"

/* Defensive include guards */

#if defined(VULKAN_H_)
#error Attempt to include auto-generated header after including vulkan.h
#endif
#if defined(VK_PLATFORM_H_)
#error Attempt to include auto-generated header after including vk_platform.h
#endif

#define VULKAN_H_
#define VK_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_GENERATING_OUTPUT /* So the macro names are preserved in the docs */

/* Function declaration macros */

#ifndef MAGNUM_BUILD_STATIC
    #ifdef FlextVk_EXPORTS
        #define FLEXTVK_EXPORT CORRADE_VISIBILITY_EXPORT
    #else
        #define FLEXTVK_EXPORT CORRADE_VISIBILITY_IMPORT
    #endif
#else
    #define FLEXTVK_EXPORT CORRADE_VISIBILITY_STATIC
#endif

/* Verbatim copied from upstream vk_platform.h */
#if defined(_WIN32)
    // On Windows, Vulkan commands use the stdcall convention
    #define VKAPI_ATTR
    #define VKAPI_CALL __stdcall
    #define VKAPI_PTR  VKAPI_CALL
#elif defined(__ANDROID__) && defined(__ARM_ARCH) && __ARM_ARCH < 7
    #error "Vulkan isn't supported for the 'armeabi' NDK ABI"
#elif defined(__ANDROID__) && defined(__ARM_ARCH) && __ARM_ARCH >= 7 && defined(__ARM_32BIT_STATE)
    // On Android 32-bit ARM targets, Vulkan functions use the "hardfloat"
    // calling convention, i.e. float parameters are passed in registers. This
    // is true even if the rest of the application passes floats on the stack,
    // as it does by default when compiling for the armeabi-v7a NDK ABI.
    #define VKAPI_ATTR __attribute__((pcs("aapcs-vfp")))
    #define VKAPI_CALL
    #define VKAPI_PTR  VKAPI_ATTR
#else
    // On other platforms, use the default calling convention
    #define VKAPI_ATTR
    #define VKAPI_CALL
    #define VKAPI_PTR
#endif

/* Enums */


#define VK_UUID_SIZE 16
#define VK_MAX_EXTENSION_NAME_SIZE 256
#define VK_MAX_DESCRIPTION_SIZE 256
#define VK_MAX_MEMORY_HEAPS 16
#define VK_MAX_PHYSICAL_DEVICE_NAME_SIZE 256
#define VK_MAX_MEMORY_TYPES 32

/* VK_VERSION_1_0 */

#define VK_LOD_CLAMP_NONE 1000.0f
#define VK_REMAINING_MIP_LEVELS (~0U)
#define VK_REMAINING_ARRAY_LAYERS (~0U)
#define VK_WHOLE_SIZE (~0ULL)
#define VK_ATTACHMENT_UNUSED (~0U)
#define VK_TRUE 1
#define VK_FALSE 0
#define VK_QUEUE_FAMILY_IGNORED (~0U)
#define VK_SUBPASS_EXTERNAL (~0U)

/* Data types */

typedef std::size_t size_t;

#define VK_MAKE_VERSION(major, minor, patch) \
    (((major) << 22) | ((minor) << 12) | (patch))
#define VK_VERSION_MAJOR(version) ((uint32_t)(version) >> 22)
#define VK_VERSION_MINOR(version) (((uint32_t)(version) >> 12) & 0x3ff)
#define VK_VERSION_PATCH(version) ((uint32_t)(version) & 0xfff)
// DEPRECATED: This define has been removed. Specific version defines (e.g. VK_API_VERSION_1_0), or the VK_MAKE_VERSION macro, should be used instead.
//#define VK_API_VERSION VK_MAKE_VERSION(1, 0, 0) // Patch version should always be set to 0
// Vulkan 1.0 version number
#define VK_API_VERSION_1_0 VK_MAKE_VERSION(1, 0, 0)// Patch version should always be set to 0
// Version of this file
#define VK_HEADER_VERSION 69

#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;

#if !defined(VK_DEFINE_NON_DISPATCHABLE_HANDLE)
#if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__) ) || defined(_M_X64) || defined(__ia64) || defined (_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
        #define VK_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef struct object##_T *object;
#else
        #define VK_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef uint64_t object;
#endif
#endif
        

#define VK_NULL_HANDLE 0
        
typedef uint32_t VkSampleMask;
typedef uint32_t VkBool32;
typedef uint32_t VkFlags;
typedef uint64_t VkDeviceSize;








typedef VkFlags VkFramebufferCreateFlags;
typedef VkFlags VkQueryPoolCreateFlags;
typedef VkFlags VkRenderPassCreateFlags;
typedef VkFlags VkSamplerCreateFlags;
typedef VkFlags VkPipelineLayoutCreateFlags;
typedef VkFlags VkPipelineCacheCreateFlags;
typedef VkFlags VkPipelineDepthStencilStateCreateFlags;
typedef VkFlags VkPipelineDynamicStateCreateFlags;
typedef VkFlags VkPipelineColorBlendStateCreateFlags;
typedef VkFlags VkPipelineMultisampleStateCreateFlags;
typedef VkFlags VkPipelineRasterizationStateCreateFlags;
typedef VkFlags VkPipelineViewportStateCreateFlags;
typedef VkFlags VkPipelineTessellationStateCreateFlags;
typedef VkFlags VkPipelineInputAssemblyStateCreateFlags;
typedef VkFlags VkPipelineVertexInputStateCreateFlags;
typedef VkFlags VkPipelineShaderStageCreateFlags;
typedef VkFlags VkDescriptorSetLayoutCreateFlags;
typedef VkFlags VkBufferViewCreateFlags;
typedef VkFlags VkInstanceCreateFlags;
typedef VkFlags VkDeviceCreateFlags;
typedef VkFlags VkDeviceQueueCreateFlags;
typedef VkFlags VkQueueFlags;
typedef VkFlags VkMemoryPropertyFlags;
typedef VkFlags VkMemoryHeapFlags;
typedef VkFlags VkAccessFlags;
typedef VkFlags VkBufferUsageFlags;
typedef VkFlags VkBufferCreateFlags;
typedef VkFlags VkShaderStageFlags;
typedef VkFlags VkImageUsageFlags;
typedef VkFlags VkImageCreateFlags;
typedef VkFlags VkImageViewCreateFlags;
typedef VkFlags VkPipelineCreateFlags;
typedef VkFlags VkColorComponentFlags;
typedef VkFlags VkFenceCreateFlags;
typedef VkFlags VkSemaphoreCreateFlags;
typedef VkFlags VkFormatFeatureFlags;
typedef VkFlags VkQueryControlFlags;
typedef VkFlags VkQueryResultFlags;
typedef VkFlags VkShaderModuleCreateFlags;
typedef VkFlags VkEventCreateFlags;
typedef VkFlags VkCommandPoolCreateFlags;
typedef VkFlags VkCommandPoolResetFlags;
typedef VkFlags VkCommandBufferResetFlags;
typedef VkFlags VkCommandBufferUsageFlags;
typedef VkFlags VkQueryPipelineStatisticFlags;
typedef VkFlags VkMemoryMapFlags;
typedef VkFlags VkImageAspectFlags;
typedef VkFlags VkSparseMemoryBindFlags;
typedef VkFlags VkSparseImageFormatFlags;
typedef VkFlags VkSubpassDescriptionFlags;
typedef VkFlags VkPipelineStageFlags;
typedef VkFlags VkSampleCountFlags;
typedef VkFlags VkAttachmentDescriptionFlags;
typedef VkFlags VkStencilFaceFlags;
typedef VkFlags VkCullModeFlags;
typedef VkFlags VkDescriptorPoolCreateFlags;
typedef VkFlags VkDescriptorPoolResetFlags;
typedef VkFlags VkDependencyFlags;
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)
VK_DEFINE_HANDLE(VkDevice)
VK_DEFINE_HANDLE(VkQueue)
VK_DEFINE_HANDLE(VkCommandBuffer)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDeviceMemory)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkCommandPool)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBuffer)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBufferView)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkImage)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkImageView)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkShaderModule)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkPipeline)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkPipelineLayout)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSampler)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorSet)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorSetLayout)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorPool)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkFence)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSemaphore)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkEvent)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkQueryPool)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkFramebuffer)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkRenderPass)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkPipelineCache)
typedef enum {
    VK_ATTACHMENT_LOAD_OP_LOAD = 0,
    VK_ATTACHMENT_LOAD_OP_CLEAR = 1,
    VK_ATTACHMENT_LOAD_OP_DONT_CARE = 2
} VkAttachmentLoadOp;

typedef enum {
    VK_ATTACHMENT_STORE_OP_STORE = 0,
    VK_ATTACHMENT_STORE_OP_DONT_CARE = 1
} VkAttachmentStoreOp;

typedef enum {
    VK_BLEND_FACTOR_ZERO = 0,
    VK_BLEND_FACTOR_ONE = 1,
    VK_BLEND_FACTOR_SRC_COLOR = 2,
    VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3,
    VK_BLEND_FACTOR_DST_COLOR = 4,
    VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR = 5,
    VK_BLEND_FACTOR_SRC_ALPHA = 6,
    VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 7,
    VK_BLEND_FACTOR_DST_ALPHA = 8,
    VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 9,
    VK_BLEND_FACTOR_CONSTANT_COLOR = 10,
    VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11,
    VK_BLEND_FACTOR_CONSTANT_ALPHA = 12,
    VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 13,
    VK_BLEND_FACTOR_SRC_ALPHA_SATURATE = 14,
    VK_BLEND_FACTOR_SRC1_COLOR = 15,
    VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR = 16,
    VK_BLEND_FACTOR_SRC1_ALPHA = 17,
    VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA = 18
} VkBlendFactor;

typedef enum {
    VK_BLEND_OP_ADD = 0,
    VK_BLEND_OP_SUBTRACT = 1,
    VK_BLEND_OP_REVERSE_SUBTRACT = 2,
    VK_BLEND_OP_MIN = 3,
    VK_BLEND_OP_MAX = 4
} VkBlendOp;

typedef enum {
    VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK = 0,
    VK_BORDER_COLOR_INT_TRANSPARENT_BLACK = 1,
    VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK = 2,
    VK_BORDER_COLOR_INT_OPAQUE_BLACK = 3,
    VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE = 4,
    VK_BORDER_COLOR_INT_OPAQUE_WHITE = 5
} VkBorderColor;

typedef enum {
    VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1
} VkPipelineCacheHeaderVersion;

typedef int VkDescriptorSetLayoutCreateFlagBits;

typedef enum {
    VK_BUFFER_CREATE_SPARSE_BINDING_BIT = 1 << 0,
    VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT = 1 << 1,
    VK_BUFFER_CREATE_SPARSE_ALIASED_BIT = 1 << 2
} VkBufferCreateFlagBits;

typedef enum {
    VK_BUFFER_USAGE_TRANSFER_SRC_BIT = 1 << 0,
    VK_BUFFER_USAGE_TRANSFER_DST_BIT = 1 << 1,
    VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT = 1 << 2,
    VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT = 1 << 3,
    VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT = 1 << 4,
    VK_BUFFER_USAGE_STORAGE_BUFFER_BIT = 1 << 5,
    VK_BUFFER_USAGE_INDEX_BUFFER_BIT = 1 << 6,
    VK_BUFFER_USAGE_VERTEX_BUFFER_BIT = 1 << 7,
    VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT = 1 << 8
} VkBufferUsageFlagBits;

typedef enum {
    VK_COLOR_COMPONENT_R_BIT = 1 << 0,
    VK_COLOR_COMPONENT_G_BIT = 1 << 1,
    VK_COLOR_COMPONENT_B_BIT = 1 << 2,
    VK_COLOR_COMPONENT_A_BIT = 1 << 3
} VkColorComponentFlagBits;

typedef enum {
    VK_COMPONENT_SWIZZLE_IDENTITY = 0,
    VK_COMPONENT_SWIZZLE_ZERO = 1,
    VK_COMPONENT_SWIZZLE_ONE = 2,
    VK_COMPONENT_SWIZZLE_R = 3,
    VK_COMPONENT_SWIZZLE_G = 4,
    VK_COMPONENT_SWIZZLE_B = 5,
    VK_COMPONENT_SWIZZLE_A = 6
} VkComponentSwizzle;

typedef enum {
    VK_COMMAND_POOL_CREATE_TRANSIENT_BIT = 1 << 0,
    VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT = 1 << 1
} VkCommandPoolCreateFlagBits;

typedef enum {
    VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT = 1 << 0
} VkCommandPoolResetFlagBits;

typedef enum {
    VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT = 1 << 0
} VkCommandBufferResetFlagBits;

typedef enum {
    VK_COMMAND_BUFFER_LEVEL_PRIMARY = 0,
    VK_COMMAND_BUFFER_LEVEL_SECONDARY = 1
} VkCommandBufferLevel;

typedef enum {
    VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT = 1 << 0,
    VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT = 1 << 1,
    VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT = 1 << 2
} VkCommandBufferUsageFlagBits;

typedef enum {
    VK_COMPARE_OP_NEVER = 0,
    VK_COMPARE_OP_LESS = 1,
    VK_COMPARE_OP_EQUAL = 2,
    VK_COMPARE_OP_LESS_OR_EQUAL = 3,
    VK_COMPARE_OP_GREATER = 4,
    VK_COMPARE_OP_NOT_EQUAL = 5,
    VK_COMPARE_OP_GREATER_OR_EQUAL = 6,
    VK_COMPARE_OP_ALWAYS = 7
} VkCompareOp;

typedef enum {
    VK_CULL_MODE_NONE = 0,
    VK_CULL_MODE_FRONT_BIT = 1 << 0,
    VK_CULL_MODE_BACK_BIT = 1 << 1,
    VK_CULL_MODE_FRONT_AND_BACK = 0x00000003
} VkCullModeFlagBits;

typedef enum {
    VK_DESCRIPTOR_TYPE_SAMPLER = 0,
    VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = 1,
    VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE = 2,
    VK_DESCRIPTOR_TYPE_STORAGE_IMAGE = 3,
    VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER = 4,
    VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER = 5,
    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER = 6,
    VK_DESCRIPTOR_TYPE_STORAGE_BUFFER = 7,
    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC = 8,
    VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC = 9,
    VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT = 10
} VkDescriptorType;

typedef enum {
    VK_DYNAMIC_STATE_VIEWPORT = 0,
    VK_DYNAMIC_STATE_SCISSOR = 1,
    VK_DYNAMIC_STATE_LINE_WIDTH = 2,
    VK_DYNAMIC_STATE_DEPTH_BIAS = 3,
    VK_DYNAMIC_STATE_BLEND_CONSTANTS = 4,
    VK_DYNAMIC_STATE_DEPTH_BOUNDS = 5,
    VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK = 6,
    VK_DYNAMIC_STATE_STENCIL_WRITE_MASK = 7,
    VK_DYNAMIC_STATE_STENCIL_REFERENCE = 8
} VkDynamicState;

typedef enum {
    VK_FENCE_CREATE_SIGNALED_BIT = 1 << 0
} VkFenceCreateFlagBits;

typedef enum {
    VK_POLYGON_MODE_FILL = 0,
    VK_POLYGON_MODE_LINE = 1,
    VK_POLYGON_MODE_POINT = 2
} VkPolygonMode;

typedef enum {
    VK_FORMAT_UNDEFINED = 0,
    VK_FORMAT_R4G4_UNORM_PACK8 = 1,
    VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
    VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
    VK_FORMAT_R5G6B5_UNORM_PACK16 = 4,
    VK_FORMAT_B5G6R5_UNORM_PACK16 = 5,
    VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
    VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
    VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
    VK_FORMAT_R8_UNORM = 9,
    VK_FORMAT_R8_SNORM = 10,
    VK_FORMAT_R8_USCALED = 11,
    VK_FORMAT_R8_SSCALED = 12,
    VK_FORMAT_R8_UINT = 13,
    VK_FORMAT_R8_SINT = 14,
    VK_FORMAT_R8_SRGB = 15,
    VK_FORMAT_R8G8_UNORM = 16,
    VK_FORMAT_R8G8_SNORM = 17,
    VK_FORMAT_R8G8_USCALED = 18,
    VK_FORMAT_R8G8_SSCALED = 19,
    VK_FORMAT_R8G8_UINT = 20,
    VK_FORMAT_R8G8_SINT = 21,
    VK_FORMAT_R8G8_SRGB = 22,
    VK_FORMAT_R8G8B8_UNORM = 23,
    VK_FORMAT_R8G8B8_SNORM = 24,
    VK_FORMAT_R8G8B8_USCALED = 25,
    VK_FORMAT_R8G8B8_SSCALED = 26,
    VK_FORMAT_R8G8B8_UINT = 27,
    VK_FORMAT_R8G8B8_SINT = 28,
    VK_FORMAT_R8G8B8_SRGB = 29,
    VK_FORMAT_B8G8R8_UNORM = 30,
    VK_FORMAT_B8G8R8_SNORM = 31,
    VK_FORMAT_B8G8R8_USCALED = 32,
    VK_FORMAT_B8G8R8_SSCALED = 33,
    VK_FORMAT_B8G8R8_UINT = 34,
    VK_FORMAT_B8G8R8_SINT = 35,
    VK_FORMAT_B8G8R8_SRGB = 36,
    VK_FORMAT_R8G8B8A8_UNORM = 37,
    VK_FORMAT_R8G8B8A8_SNORM = 38,
    VK_FORMAT_R8G8B8A8_USCALED = 39,
    VK_FORMAT_R8G8B8A8_SSCALED = 40,
    VK_FORMAT_R8G8B8A8_UINT = 41,
    VK_FORMAT_R8G8B8A8_SINT = 42,
    VK_FORMAT_R8G8B8A8_SRGB = 43,
    VK_FORMAT_B8G8R8A8_UNORM = 44,
    VK_FORMAT_B8G8R8A8_SNORM = 45,
    VK_FORMAT_B8G8R8A8_USCALED = 46,
    VK_FORMAT_B8G8R8A8_SSCALED = 47,
    VK_FORMAT_B8G8R8A8_UINT = 48,
    VK_FORMAT_B8G8R8A8_SINT = 49,
    VK_FORMAT_B8G8R8A8_SRGB = 50,
    VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
    VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
    VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
    VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
    VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
    VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
    VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
    VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
    VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
    VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
    VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
    VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
    VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
    VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
    VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
    VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
    VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
    VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
    VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
    VK_FORMAT_R16_UNORM = 70,
    VK_FORMAT_R16_SNORM = 71,
    VK_FORMAT_R16_USCALED = 72,
    VK_FORMAT_R16_SSCALED = 73,
    VK_FORMAT_R16_UINT = 74,
    VK_FORMAT_R16_SINT = 75,
    VK_FORMAT_R16_SFLOAT = 76,
    VK_FORMAT_R16G16_UNORM = 77,
    VK_FORMAT_R16G16_SNORM = 78,
    VK_FORMAT_R16G16_USCALED = 79,
    VK_FORMAT_R16G16_SSCALED = 80,
    VK_FORMAT_R16G16_UINT = 81,
    VK_FORMAT_R16G16_SINT = 82,
    VK_FORMAT_R16G16_SFLOAT = 83,
    VK_FORMAT_R16G16B16_UNORM = 84,
    VK_FORMAT_R16G16B16_SNORM = 85,
    VK_FORMAT_R16G16B16_USCALED = 86,
    VK_FORMAT_R16G16B16_SSCALED = 87,
    VK_FORMAT_R16G16B16_UINT = 88,
    VK_FORMAT_R16G16B16_SINT = 89,
    VK_FORMAT_R16G16B16_SFLOAT = 90,
    VK_FORMAT_R16G16B16A16_UNORM = 91,
    VK_FORMAT_R16G16B16A16_SNORM = 92,
    VK_FORMAT_R16G16B16A16_USCALED = 93,
    VK_FORMAT_R16G16B16A16_SSCALED = 94,
    VK_FORMAT_R16G16B16A16_UINT = 95,
    VK_FORMAT_R16G16B16A16_SINT = 96,
    VK_FORMAT_R16G16B16A16_SFLOAT = 97,
    VK_FORMAT_R32_UINT = 98,
    VK_FORMAT_R32_SINT = 99,
    VK_FORMAT_R32_SFLOAT = 100,
    VK_FORMAT_R32G32_UINT = 101,
    VK_FORMAT_R32G32_SINT = 102,
    VK_FORMAT_R32G32_SFLOAT = 103,
    VK_FORMAT_R32G32B32_UINT = 104,
    VK_FORMAT_R32G32B32_SINT = 105,
    VK_FORMAT_R32G32B32_SFLOAT = 106,
    VK_FORMAT_R32G32B32A32_UINT = 107,
    VK_FORMAT_R32G32B32A32_SINT = 108,
    VK_FORMAT_R32G32B32A32_SFLOAT = 109,
    VK_FORMAT_R64_UINT = 110,
    VK_FORMAT_R64_SINT = 111,
    VK_FORMAT_R64_SFLOAT = 112,
    VK_FORMAT_R64G64_UINT = 113,
    VK_FORMAT_R64G64_SINT = 114,
    VK_FORMAT_R64G64_SFLOAT = 115,
    VK_FORMAT_R64G64B64_UINT = 116,
    VK_FORMAT_R64G64B64_SINT = 117,
    VK_FORMAT_R64G64B64_SFLOAT = 118,
    VK_FORMAT_R64G64B64A64_UINT = 119,
    VK_FORMAT_R64G64B64A64_SINT = 120,
    VK_FORMAT_R64G64B64A64_SFLOAT = 121,
    VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
    VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
    VK_FORMAT_D16_UNORM = 124,
    VK_FORMAT_X8_D24_UNORM_PACK32 = 125,
    VK_FORMAT_D32_SFLOAT = 126,
    VK_FORMAT_S8_UINT = 127,
    VK_FORMAT_D16_UNORM_S8_UINT = 128,
    VK_FORMAT_D24_UNORM_S8_UINT = 129,
    VK_FORMAT_D32_SFLOAT_S8_UINT = 130,
    VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
    VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
    VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
    VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
    VK_FORMAT_BC2_UNORM_BLOCK = 135,
    VK_FORMAT_BC2_SRGB_BLOCK = 136,
    VK_FORMAT_BC3_UNORM_BLOCK = 137,
    VK_FORMAT_BC3_SRGB_BLOCK = 138,
    VK_FORMAT_BC4_UNORM_BLOCK = 139,
    VK_FORMAT_BC4_SNORM_BLOCK = 140,
    VK_FORMAT_BC5_UNORM_BLOCK = 141,
    VK_FORMAT_BC5_SNORM_BLOCK = 142,
    VK_FORMAT_BC6H_UFLOAT_BLOCK = 143,
    VK_FORMAT_BC6H_SFLOAT_BLOCK = 144,
    VK_FORMAT_BC7_UNORM_BLOCK = 145,
    VK_FORMAT_BC7_SRGB_BLOCK = 146,
    VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
    VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
    VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
    VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
    VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
    VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
    VK_FORMAT_EAC_R11_UNORM_BLOCK = 153,
    VK_FORMAT_EAC_R11_SNORM_BLOCK = 154,
    VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
    VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
    VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
    VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
    VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
    VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
    VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
    VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
    VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
    VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
    VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
    VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
    VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
    VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
    VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
    VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
    VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
    VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
    VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
    VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
    VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
    VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
    VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
    VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
    VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
    VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
    VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
    VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
    VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
    VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184
} VkFormat;

typedef enum {
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT = 1 << 0,
    VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT = 1 << 1,
    VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT = 1 << 2,
    VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT = 1 << 3,
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT = 1 << 4,
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT = 1 << 5,
    VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT = 1 << 6,
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT = 1 << 7,
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT = 1 << 8,
    VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT = 1 << 9,
    VK_FORMAT_FEATURE_BLIT_SRC_BIT = 1 << 10,
    VK_FORMAT_FEATURE_BLIT_DST_BIT = 1 << 11,
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT = 1 << 12
} VkFormatFeatureFlagBits;

typedef enum {
    VK_FRONT_FACE_COUNTER_CLOCKWISE = 0,
    VK_FRONT_FACE_CLOCKWISE = 1
} VkFrontFace;

typedef enum {
    VK_IMAGE_ASPECT_COLOR_BIT = 1 << 0,
    VK_IMAGE_ASPECT_DEPTH_BIT = 1 << 1,
    VK_IMAGE_ASPECT_STENCIL_BIT = 1 << 2,
    VK_IMAGE_ASPECT_METADATA_BIT = 1 << 3
} VkImageAspectFlagBits;

typedef enum {
    VK_IMAGE_CREATE_SPARSE_BINDING_BIT = 1 << 0,
    VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT = 1 << 1,
    VK_IMAGE_CREATE_SPARSE_ALIASED_BIT = 1 << 2,
    VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT = 1 << 3,
    VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT = 1 << 4
} VkImageCreateFlagBits;

typedef enum {
    VK_IMAGE_LAYOUT_UNDEFINED = 0,
    VK_IMAGE_LAYOUT_GENERAL = 1,
    VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL = 2,
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL = 3,
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL = 4,
    VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL = 5,
    VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL = 6,
    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL = 7,
    VK_IMAGE_LAYOUT_PREINITIALIZED = 8
} VkImageLayout;

typedef enum {
    VK_IMAGE_TILING_OPTIMAL = 0,
    VK_IMAGE_TILING_LINEAR = 1
} VkImageTiling;

typedef enum {
    VK_IMAGE_TYPE_1D = 0,
    VK_IMAGE_TYPE_2D = 1,
    VK_IMAGE_TYPE_3D = 2
} VkImageType;

typedef enum {
    VK_IMAGE_USAGE_TRANSFER_SRC_BIT = 1 << 0,
    VK_IMAGE_USAGE_TRANSFER_DST_BIT = 1 << 1,
    VK_IMAGE_USAGE_SAMPLED_BIT = 1 << 2,
    VK_IMAGE_USAGE_STORAGE_BIT = 1 << 3,
    VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT = 1 << 4,
    VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT = 1 << 5,
    VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT = 1 << 6,
    VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT = 1 << 7
} VkImageUsageFlagBits;

typedef enum {
    VK_IMAGE_VIEW_TYPE_1D = 0,
    VK_IMAGE_VIEW_TYPE_2D = 1,
    VK_IMAGE_VIEW_TYPE_3D = 2,
    VK_IMAGE_VIEW_TYPE_CUBE = 3,
    VK_IMAGE_VIEW_TYPE_1D_ARRAY = 4,
    VK_IMAGE_VIEW_TYPE_2D_ARRAY = 5,
    VK_IMAGE_VIEW_TYPE_CUBE_ARRAY = 6
} VkImageViewType;

typedef enum {
    VK_SHARING_MODE_EXCLUSIVE = 0,
    VK_SHARING_MODE_CONCURRENT = 1
} VkSharingMode;

typedef enum {
    VK_INDEX_TYPE_UINT16 = 0,
    VK_INDEX_TYPE_UINT32 = 1
} VkIndexType;

typedef enum {
    VK_LOGIC_OP_CLEAR = 0,
    VK_LOGIC_OP_AND = 1,
    VK_LOGIC_OP_AND_REVERSE = 2,
    VK_LOGIC_OP_COPY = 3,
    VK_LOGIC_OP_AND_INVERTED = 4,
    VK_LOGIC_OP_NO_OP = 5,
    VK_LOGIC_OP_XOR = 6,
    VK_LOGIC_OP_OR = 7,
    VK_LOGIC_OP_NOR = 8,
    VK_LOGIC_OP_EQUIVALENT = 9,
    VK_LOGIC_OP_INVERT = 10,
    VK_LOGIC_OP_OR_REVERSE = 11,
    VK_LOGIC_OP_COPY_INVERTED = 12,
    VK_LOGIC_OP_OR_INVERTED = 13,
    VK_LOGIC_OP_NAND = 14,
    VK_LOGIC_OP_SET = 15
} VkLogicOp;

typedef enum {
    VK_MEMORY_HEAP_DEVICE_LOCAL_BIT = 1 << 0
} VkMemoryHeapFlagBits;

typedef enum {
    VK_ACCESS_INDIRECT_COMMAND_READ_BIT = 1 << 0,
    VK_ACCESS_INDEX_READ_BIT = 1 << 1,
    VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT = 1 << 2,
    VK_ACCESS_UNIFORM_READ_BIT = 1 << 3,
    VK_ACCESS_INPUT_ATTACHMENT_READ_BIT = 1 << 4,
    VK_ACCESS_SHADER_READ_BIT = 1 << 5,
    VK_ACCESS_SHADER_WRITE_BIT = 1 << 6,
    VK_ACCESS_COLOR_ATTACHMENT_READ_BIT = 1 << 7,
    VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT = 1 << 8,
    VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT = 1 << 9,
    VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT = 1 << 10,
    VK_ACCESS_TRANSFER_READ_BIT = 1 << 11,
    VK_ACCESS_TRANSFER_WRITE_BIT = 1 << 12,
    VK_ACCESS_HOST_READ_BIT = 1 << 13,
    VK_ACCESS_HOST_WRITE_BIT = 1 << 14,
    VK_ACCESS_MEMORY_READ_BIT = 1 << 15,
    VK_ACCESS_MEMORY_WRITE_BIT = 1 << 16
} VkAccessFlagBits;

typedef enum {
    VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 1 << 0,
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 1 << 1,
    VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 1 << 2,
    VK_MEMORY_PROPERTY_HOST_CACHED_BIT = 1 << 3,
    VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT = 1 << 4
} VkMemoryPropertyFlagBits;

typedef enum {
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4
} VkPhysicalDeviceType;

typedef enum {
    VK_PIPELINE_BIND_POINT_GRAPHICS = 0,
    VK_PIPELINE_BIND_POINT_COMPUTE = 1
} VkPipelineBindPoint;

typedef enum {
    VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT = 1 << 0,
    VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT = 1 << 1,
    VK_PIPELINE_CREATE_DERIVATIVE_BIT = 1 << 2
} VkPipelineCreateFlagBits;

typedef enum {
    VK_PRIMITIVE_TOPOLOGY_POINT_LIST = 0,
    VK_PRIMITIVE_TOPOLOGY_LINE_LIST = 1,
    VK_PRIMITIVE_TOPOLOGY_LINE_STRIP = 2,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST = 3,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 4,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN = 5,
    VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY = 6,
    VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY = 7,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY = 8,
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY = 9,
    VK_PRIMITIVE_TOPOLOGY_PATCH_LIST = 10
} VkPrimitiveTopology;

typedef enum {
    VK_QUERY_CONTROL_PRECISE_BIT = 1 << 0
} VkQueryControlFlagBits;

typedef enum {
    VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT = 1 << 0,
    VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT = 1 << 1,
    VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT = 1 << 2,
    VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT = 1 << 3,
    VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT = 1 << 4,
    VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT = 1 << 5,
    VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT = 1 << 6,
    VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT = 1 << 7,
    VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT = 1 << 8,
    VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT = 1 << 9,
    VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT = 1 << 10
} VkQueryPipelineStatisticFlagBits;

typedef enum {
    VK_QUERY_RESULT_64_BIT = 1 << 0,
    VK_QUERY_RESULT_WAIT_BIT = 1 << 1,
    VK_QUERY_RESULT_WITH_AVAILABILITY_BIT = 1 << 2,
    VK_QUERY_RESULT_PARTIAL_BIT = 1 << 3
} VkQueryResultFlagBits;

typedef enum {
    VK_QUERY_TYPE_OCCLUSION = 0,
    VK_QUERY_TYPE_PIPELINE_STATISTICS = 1,
    VK_QUERY_TYPE_TIMESTAMP = 2
} VkQueryType;

typedef enum {
    VK_QUEUE_GRAPHICS_BIT = 1 << 0,
    VK_QUEUE_COMPUTE_BIT = 1 << 1,
    VK_QUEUE_TRANSFER_BIT = 1 << 2,
    VK_QUEUE_SPARSE_BINDING_BIT = 1 << 3
} VkQueueFlagBits;

typedef enum {
    VK_SUBPASS_CONTENTS_INLINE = 0,
    VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS = 1
} VkSubpassContents;

typedef enum {
    VK_SUCCESS = 0,
    VK_NOT_READY = 1,
    VK_TIMEOUT = 2,
    VK_EVENT_SET = 3,
    VK_EVENT_RESET = 4,
    VK_INCOMPLETE = 5,
    VK_ERROR_OUT_OF_HOST_MEMORY = -1,
    VK_ERROR_OUT_OF_DEVICE_MEMORY = -2,
    VK_ERROR_INITIALIZATION_FAILED = -3,
    VK_ERROR_DEVICE_LOST = -4,
    VK_ERROR_MEMORY_MAP_FAILED = -5,
    VK_ERROR_LAYER_NOT_PRESENT = -6,
    VK_ERROR_EXTENSION_NOT_PRESENT = -7,
    VK_ERROR_FEATURE_NOT_PRESENT = -8,
    VK_ERROR_INCOMPATIBLE_DRIVER = -9,
    VK_ERROR_TOO_MANY_OBJECTS = -10,
    VK_ERROR_FORMAT_NOT_SUPPORTED = -11,
    VK_ERROR_FRAGMENTED_POOL = -12
} VkResult;

typedef enum {
    VK_SHADER_STAGE_VERTEX_BIT = 1 << 0,
    VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT = 1 << 1,
    VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT = 1 << 2,
    VK_SHADER_STAGE_GEOMETRY_BIT = 1 << 3,
    VK_SHADER_STAGE_FRAGMENT_BIT = 1 << 4,
    VK_SHADER_STAGE_COMPUTE_BIT = 1 << 5,
    VK_SHADER_STAGE_ALL_GRAPHICS = 0x0000001F,
    VK_SHADER_STAGE_ALL = 0x7FFFFFFF
} VkShaderStageFlagBits;

typedef enum {
    VK_SPARSE_MEMORY_BIND_METADATA_BIT = 1 << 0
} VkSparseMemoryBindFlagBits;

typedef enum {
    VK_STENCIL_FACE_FRONT_BIT = 1 << 0,
    VK_STENCIL_FACE_BACK_BIT = 1 << 1,
    VK_STENCIL_FRONT_AND_BACK = 0x00000003
} VkStencilFaceFlagBits;

typedef enum {
    VK_STENCIL_OP_KEEP = 0,
    VK_STENCIL_OP_ZERO = 1,
    VK_STENCIL_OP_REPLACE = 2,
    VK_STENCIL_OP_INCREMENT_AND_CLAMP = 3,
    VK_STENCIL_OP_DECREMENT_AND_CLAMP = 4,
    VK_STENCIL_OP_INVERT = 5,
    VK_STENCIL_OP_INCREMENT_AND_WRAP = 6,
    VK_STENCIL_OP_DECREMENT_AND_WRAP = 7
} VkStencilOp;

typedef enum {
    VK_STRUCTURE_TYPE_APPLICATION_INFO = 0,
    VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1,
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO = 2,
    VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO = 3,
    VK_STRUCTURE_TYPE_SUBMIT_INFO = 4,
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO = 5,
    VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE = 6,
    VK_STRUCTURE_TYPE_BIND_SPARSE_INFO = 7,
    VK_STRUCTURE_TYPE_FENCE_CREATE_INFO = 8,
    VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO = 9,
    VK_STRUCTURE_TYPE_EVENT_CREATE_INFO = 10,
    VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO = 11,
    VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO = 12,
    VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO = 13,
    VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO = 14,
    VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO = 15,
    VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO = 16,
    VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO = 17,
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO = 18,
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO = 19,
    VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO = 20,
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO = 21,
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO = 22,
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO = 23,
    VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO = 24,
    VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO = 25,
    VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO = 26,
    VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO = 27,
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO = 28,
    VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO = 29,
    VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO = 30,
    VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO = 31,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO = 32,
    VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO = 33,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO = 34,
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET = 35,
    VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET = 36,
    VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO = 37,
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO = 38,
    VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO = 39,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO = 40,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO = 41,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO = 42,
    VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO = 43,
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER = 44,
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER = 45,
    VK_STRUCTURE_TYPE_MEMORY_BARRIER = 46,
    VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO = 47,
    VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO = 48
} VkStructureType;

typedef enum {
    VK_SYSTEM_ALLOCATION_SCOPE_COMMAND = 0,
    VK_SYSTEM_ALLOCATION_SCOPE_OBJECT = 1,
    VK_SYSTEM_ALLOCATION_SCOPE_CACHE = 2,
    VK_SYSTEM_ALLOCATION_SCOPE_DEVICE = 3,
    VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE = 4
} VkSystemAllocationScope;

typedef enum {
    VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE = 0
} VkInternalAllocationType;

typedef enum {
    VK_SAMPLER_ADDRESS_MODE_REPEAT = 0,
    VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT = 1,
    VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE = 2,
    VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER = 3
} VkSamplerAddressMode;

typedef enum {
    VK_FILTER_NEAREST = 0,
    VK_FILTER_LINEAR = 1
} VkFilter;

typedef enum {
    VK_SAMPLER_MIPMAP_MODE_NEAREST = 0,
    VK_SAMPLER_MIPMAP_MODE_LINEAR = 1
} VkSamplerMipmapMode;

typedef enum {
    VK_VERTEX_INPUT_RATE_VERTEX = 0,
    VK_VERTEX_INPUT_RATE_INSTANCE = 1
} VkVertexInputRate;

typedef enum {
    VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT = 1 << 0,
    VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT = 1 << 1,
    VK_PIPELINE_STAGE_VERTEX_INPUT_BIT = 1 << 2,
    VK_PIPELINE_STAGE_VERTEX_SHADER_BIT = 1 << 3,
    VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT = 1 << 4,
    VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT = 1 << 5,
    VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT = 1 << 6,
    VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT = 1 << 7,
    VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT = 1 << 8,
    VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT = 1 << 9,
    VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT = 1 << 10,
    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT = 1 << 11,
    VK_PIPELINE_STAGE_TRANSFER_BIT = 1 << 12,
    VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT = 1 << 13,
    VK_PIPELINE_STAGE_HOST_BIT = 1 << 14,
    VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT = 1 << 15,
    VK_PIPELINE_STAGE_ALL_COMMANDS_BIT = 1 << 16
} VkPipelineStageFlagBits;

typedef enum {
    VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT = 1 << 0,
    VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT = 1 << 1,
    VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT = 1 << 2
} VkSparseImageFormatFlagBits;

typedef enum {
    VK_SAMPLE_COUNT_1_BIT = 1 << 0,
    VK_SAMPLE_COUNT_2_BIT = 1 << 1,
    VK_SAMPLE_COUNT_4_BIT = 1 << 2,
    VK_SAMPLE_COUNT_8_BIT = 1 << 3,
    VK_SAMPLE_COUNT_16_BIT = 1 << 4,
    VK_SAMPLE_COUNT_32_BIT = 1 << 5,
    VK_SAMPLE_COUNT_64_BIT = 1 << 6
} VkSampleCountFlagBits;

typedef enum {
    VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT = 1 << 0
} VkAttachmentDescriptionFlagBits;

typedef enum {
    VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT = 1 << 0
} VkDescriptorPoolCreateFlagBits;

typedef enum {
    VK_DEPENDENCY_BY_REGION_BIT = 1 << 0
} VkDependencyFlagBits;

typedef enum {
    VK_OBJECT_TYPE_UNKNOWN = 0,
    VK_OBJECT_TYPE_INSTANCE = 1,
    VK_OBJECT_TYPE_PHYSICAL_DEVICE = 2,
    VK_OBJECT_TYPE_DEVICE = 3,
    VK_OBJECT_TYPE_QUEUE = 4,
    VK_OBJECT_TYPE_SEMAPHORE = 5,
    VK_OBJECT_TYPE_COMMAND_BUFFER = 6,
    VK_OBJECT_TYPE_FENCE = 7,
    VK_OBJECT_TYPE_DEVICE_MEMORY = 8,
    VK_OBJECT_TYPE_BUFFER = 9,
    VK_OBJECT_TYPE_IMAGE = 10,
    VK_OBJECT_TYPE_EVENT = 11,
    VK_OBJECT_TYPE_QUERY_POOL = 12,
    VK_OBJECT_TYPE_BUFFER_VIEW = 13,
    VK_OBJECT_TYPE_IMAGE_VIEW = 14,
    VK_OBJECT_TYPE_SHADER_MODULE = 15,
    VK_OBJECT_TYPE_PIPELINE_CACHE = 16,
    VK_OBJECT_TYPE_PIPELINE_LAYOUT = 17,
    VK_OBJECT_TYPE_RENDER_PASS = 18,
    VK_OBJECT_TYPE_PIPELINE = 19,
    VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT = 20,
    VK_OBJECT_TYPE_SAMPLER = 21,
    VK_OBJECT_TYPE_DESCRIPTOR_POOL = 22,
    VK_OBJECT_TYPE_DESCRIPTOR_SET = 23,
    VK_OBJECT_TYPE_FRAMEBUFFER = 24,
    VK_OBJECT_TYPE_COMMAND_POOL = 25
} VkObjectType;

typedef int VkSubpassDescriptionFlagBits;

typedef void (VKAPI_PTR *PFN_vkInternalAllocationNotification)(
    void*                                       pUserData,
    size_t                                      size,
    VkInternalAllocationType                    allocationType,
    VkSystemAllocationScope                     allocationScope);
typedef void (VKAPI_PTR *PFN_vkInternalFreeNotification)(
    void*                                       pUserData,
    size_t                                      size,
    VkInternalAllocationType                    allocationType,
    VkSystemAllocationScope                     allocationScope);
typedef void* (VKAPI_PTR *PFN_vkReallocationFunction)(
    void*                                       pUserData,
    void*                                       pOriginal,
    size_t                                      size,
    size_t                                      alignment,
    VkSystemAllocationScope                     allocationScope);
typedef void* (VKAPI_PTR *PFN_vkAllocationFunction)(
    void*                                       pUserData,
    size_t                                      size,
    size_t                                      alignment,
    VkSystemAllocationScope                     allocationScope);
typedef void (VKAPI_PTR *PFN_vkFreeFunction)(
    void*                                       pUserData,
    void*                                       pMemory);
typedef void (VKAPI_PTR *PFN_vkVoidFunction)(void);
typedef struct {
    int32_t        x;
    int32_t        y;
} VkOffset2D;

typedef struct {
    int32_t        x;
    int32_t        y;
    int32_t        z;
} VkOffset3D;

typedef struct {
    uint32_t        width;
    uint32_t        height;
} VkExtent2D;

typedef struct {
    uint32_t        width;
    uint32_t        height;
    uint32_t        depth;
} VkExtent3D;

typedef struct {
    float          x;
    float          y;
    float          width;
    float          height;
    float          minDepth;
    float          maxDepth;
} VkViewport;

typedef struct {
    VkOffset2D     offset;
    VkExtent2D     extent;
} VkRect2D;

typedef struct {
    VkRect2D       rect;
    uint32_t       baseArrayLayer;
    uint32_t       layerCount;
} VkClearRect;

typedef struct {
    VkComponentSwizzle r;
    VkComponentSwizzle g;
    VkComponentSwizzle b;
    VkComponentSwizzle a;
} VkComponentMapping;

typedef struct {
    char            extensionName[VK_MAX_EXTENSION_NAME_SIZE];
    uint32_t        specVersion;
} VkExtensionProperties;

typedef struct {
    char            layerName[VK_MAX_EXTENSION_NAME_SIZE];
    uint32_t        specVersion;
    uint32_t        implementationVersion;
    char            description[VK_MAX_DESCRIPTION_SIZE];
} VkLayerProperties;

typedef struct {
    VkStructureType sType;
    const void*     pNext;
    const char*     pApplicationName;
    uint32_t        applicationVersion;
    const char*     pEngineName;
    uint32_t        engineVersion;
    uint32_t        apiVersion;
} VkApplicationInfo;

typedef struct {
    void*           pUserData;
    PFN_vkAllocationFunction   pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction    pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
} VkAllocationCallbacks;

typedef struct {
    VkStructureType sType;
    const void*     pNext;
    VkDeviceQueueCreateFlags    flags;
    uint32_t        queueFamilyIndex;
    uint32_t        queueCount;
    const float*    pQueuePriorities;
} VkDeviceQueueCreateInfo;

typedef struct {
    VkBool32               robustBufferAccess;
    VkBool32               fullDrawIndexUint32;
    VkBool32               imageCubeArray;
    VkBool32               independentBlend;
    VkBool32               geometryShader;
    VkBool32               tessellationShader;
    VkBool32               sampleRateShading;
    VkBool32               dualSrcBlend;
    VkBool32               logicOp;
    VkBool32               multiDrawIndirect;
    VkBool32               drawIndirectFirstInstance;
    VkBool32               depthClamp;
    VkBool32               depthBiasClamp;
    VkBool32               fillModeNonSolid;
    VkBool32               depthBounds;
    VkBool32               wideLines;
    VkBool32               largePoints;
    VkBool32               alphaToOne;
    VkBool32               multiViewport;
    VkBool32               samplerAnisotropy;
    VkBool32               textureCompressionETC2;
    VkBool32               textureCompressionASTC_LDR;
    VkBool32               textureCompressionBC;
    VkBool32               occlusionQueryPrecise;
    VkBool32               pipelineStatisticsQuery;
    VkBool32               vertexPipelineStoresAndAtomics;
    VkBool32               fragmentStoresAndAtomics;
    VkBool32               shaderTessellationAndGeometryPointSize;
    VkBool32               shaderImageGatherExtended;
    VkBool32               shaderStorageImageExtendedFormats;
    VkBool32               shaderStorageImageMultisample;
    VkBool32               shaderStorageImageReadWithoutFormat;
    VkBool32               shaderStorageImageWriteWithoutFormat;
    VkBool32               shaderUniformBufferArrayDynamicIndexing;
    VkBool32               shaderSampledImageArrayDynamicIndexing;
    VkBool32               shaderStorageBufferArrayDynamicIndexing;
    VkBool32               shaderStorageImageArrayDynamicIndexing;
    VkBool32               shaderClipDistance;
    VkBool32               shaderCullDistance;
    VkBool32               shaderFloat64;
    VkBool32               shaderInt64;
    VkBool32               shaderInt16;
    VkBool32               shaderResourceResidency;
    VkBool32               shaderResourceMinLod;
    VkBool32               sparseBinding;
    VkBool32               sparseResidencyBuffer;
    VkBool32               sparseResidencyImage2D;
    VkBool32               sparseResidencyImage3D;
    VkBool32               sparseResidency2Samples;
    VkBool32               sparseResidency4Samples;
    VkBool32               sparseResidency8Samples;
    VkBool32               sparseResidency16Samples;
    VkBool32               sparseResidencyAliased;
    VkBool32               variableMultisampleRate;
    VkBool32               inheritedQueries;
} VkPhysicalDeviceFeatures;

typedef struct {
    VkStructureType sType;
    const void*     pNext;
    VkDeviceCreateFlags    flags;
    uint32_t        queueCreateInfoCount;
    const VkDeviceQueueCreateInfo* pQueueCreateInfos;
    uint32_t               enabledLayerCount;
    const char* const*      ppEnabledLayerNames;
    uint32_t               enabledExtensionCount;
    const char* const*      ppEnabledExtensionNames;
    const VkPhysicalDeviceFeatures* pEnabledFeatures;
} VkDeviceCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*     pNext;
    VkInstanceCreateFlags  flags;
    const VkApplicationInfo* pApplicationInfo;
    uint32_t               enabledLayerCount;
    const char* const*      ppEnabledLayerNames;
    uint32_t               enabledExtensionCount;
    const char* const*      ppEnabledExtensionNames;
} VkInstanceCreateInfo;

typedef struct {
    VkQueueFlags           queueFlags;
    uint32_t               queueCount;
    uint32_t               timestampValidBits;
    VkExtent3D             minImageTransferGranularity;
} VkQueueFamilyProperties;

typedef struct {
    VkMemoryPropertyFlags  propertyFlags;
    uint32_t               heapIndex;
} VkMemoryType;

typedef struct {
    VkDeviceSize           size;
    VkMemoryHeapFlags      flags;
} VkMemoryHeap;

typedef struct {
    uint32_t               memoryTypeCount;
    VkMemoryType           memoryTypes[VK_MAX_MEMORY_TYPES];
    uint32_t               memoryHeapCount;
    VkMemoryHeap           memoryHeaps[VK_MAX_MEMORY_HEAPS];
} VkPhysicalDeviceMemoryProperties;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDeviceSize           allocationSize;
    uint32_t               memoryTypeIndex;
} VkMemoryAllocateInfo;

typedef struct {
    VkDeviceSize           size;
    VkDeviceSize           alignment;
    uint32_t               memoryTypeBits;
} VkMemoryRequirements;

typedef struct {
    VkImageAspectFlags     aspectMask;
    VkExtent3D             imageGranularity;
    VkSparseImageFormatFlags flags;
} VkSparseImageFormatProperties;

typedef struct {
    VkSparseImageFormatProperties formatProperties;
    uint32_t               imageMipTailFirstLod;
    VkDeviceSize           imageMipTailSize;
    VkDeviceSize           imageMipTailOffset;
    VkDeviceSize           imageMipTailStride;
} VkSparseImageMemoryRequirements;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDeviceMemory         memory;
    VkDeviceSize           offset;
    VkDeviceSize           size;
} VkMappedMemoryRange;

typedef struct {
    VkFormatFeatureFlags   linearTilingFeatures;
    VkFormatFeatureFlags   optimalTilingFeatures;
    VkFormatFeatureFlags   bufferFeatures;
} VkFormatProperties;

typedef struct {
    VkExtent3D             maxExtent;
    uint32_t               maxMipLevels;
    uint32_t               maxArrayLayers;
    VkSampleCountFlags     sampleCounts;
    VkDeviceSize           maxResourceSize;
} VkImageFormatProperties;

typedef struct {
    VkBuffer               buffer;
    VkDeviceSize           offset;
    VkDeviceSize           range;
} VkDescriptorBufferInfo;

typedef struct {
    VkSampler       sampler;
    VkImageView     imageView;
    VkImageLayout   imageLayout;
} VkDescriptorImageInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDescriptorSet        dstSet;
    uint32_t               dstBinding;
    uint32_t               dstArrayElement;
    uint32_t               descriptorCount;
    VkDescriptorType       descriptorType;
    const VkDescriptorImageInfo* pImageInfo;
    const VkDescriptorBufferInfo* pBufferInfo;
    const VkBufferView*    pTexelBufferView;
} VkWriteDescriptorSet;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDescriptorSet        srcSet;
    uint32_t               srcBinding;
    uint32_t               srcArrayElement;
    VkDescriptorSet        dstSet;
    uint32_t               dstBinding;
    uint32_t               dstArrayElement;
    uint32_t               descriptorCount;
} VkCopyDescriptorSet;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkBufferCreateFlags    flags;
    VkDeviceSize           size;
    VkBufferUsageFlags     usage;
    VkSharingMode          sharingMode;
    uint32_t               queueFamilyIndexCount;
    const uint32_t*        pQueueFamilyIndices;
} VkBufferCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkBufferViewCreateFlags flags;
    VkBuffer               buffer;
    VkFormat               format;
    VkDeviceSize           offset;
    VkDeviceSize           range;
} VkBufferViewCreateInfo;

typedef struct {
    VkImageAspectFlags     aspectMask;
    uint32_t               mipLevel;
    uint32_t               arrayLayer;
} VkImageSubresource;

typedef struct {
    VkImageAspectFlags     aspectMask;
    uint32_t               mipLevel;
    uint32_t               baseArrayLayer;
    uint32_t               layerCount;
} VkImageSubresourceLayers;

typedef struct {
    VkImageAspectFlags     aspectMask;
    uint32_t               baseMipLevel;
    uint32_t               levelCount;
    uint32_t               baseArrayLayer;
    uint32_t               layerCount;
} VkImageSubresourceRange;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkAccessFlags          srcAccessMask;
    VkAccessFlags          dstAccessMask;
} VkMemoryBarrier;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkAccessFlags          srcAccessMask;
    VkAccessFlags          dstAccessMask;
    uint32_t               srcQueueFamilyIndex;
    uint32_t               dstQueueFamilyIndex;
    VkBuffer               buffer;
    VkDeviceSize           offset;
    VkDeviceSize           size;
} VkBufferMemoryBarrier;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkAccessFlags          srcAccessMask;
    VkAccessFlags          dstAccessMask;
    VkImageLayout          oldLayout;
    VkImageLayout          newLayout;
    uint32_t               srcQueueFamilyIndex;
    uint32_t               dstQueueFamilyIndex;
    VkImage                image;
    VkImageSubresourceRange subresourceRange;
} VkImageMemoryBarrier;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkImageCreateFlags     flags;
    VkImageType            imageType;
    VkFormat               format;
    VkExtent3D             extent;
    uint32_t               mipLevels;
    uint32_t               arrayLayers;
    VkSampleCountFlagBits  samples;
    VkImageTiling          tiling;
    VkImageUsageFlags      usage;
    VkSharingMode          sharingMode;
    uint32_t               queueFamilyIndexCount;
    const uint32_t*        pQueueFamilyIndices;
    VkImageLayout          initialLayout;
} VkImageCreateInfo;

typedef struct {
    VkDeviceSize           offset;
    VkDeviceSize           size;
    VkDeviceSize           rowPitch;
    VkDeviceSize           arrayPitch;
    VkDeviceSize           depthPitch;
} VkSubresourceLayout;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkImageViewCreateFlags flags;
    VkImage                image;
    VkImageViewType        viewType;
    VkFormat               format;
    VkComponentMapping     components;
    VkImageSubresourceRange subresourceRange;
} VkImageViewCreateInfo;

typedef struct {
    VkDeviceSize           srcOffset;
    VkDeviceSize           dstOffset;
    VkDeviceSize           size;
} VkBufferCopy;

typedef struct {
    VkDeviceSize           resourceOffset;
    VkDeviceSize           size;
    VkDeviceMemory         memory;
    VkDeviceSize           memoryOffset;
    VkSparseMemoryBindFlags flags;
} VkSparseMemoryBind;

typedef struct {
    VkImageSubresource     subresource;
    VkOffset3D             offset;
    VkExtent3D             extent;
    VkDeviceMemory         memory;
    VkDeviceSize           memoryOffset;
    VkSparseMemoryBindFlags flags;
} VkSparseImageMemoryBind;

typedef struct {
    VkBuffer buffer;
    uint32_t               bindCount;
    const VkSparseMemoryBind* pBinds;
} VkSparseBufferMemoryBindInfo;

typedef struct {
    VkImage image;
    uint32_t               bindCount;
    const VkSparseMemoryBind* pBinds;
} VkSparseImageOpaqueMemoryBindInfo;

typedef struct {
    VkImage image;
    uint32_t               bindCount;
    const VkSparseImageMemoryBind* pBinds;
} VkSparseImageMemoryBindInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    uint32_t               waitSemaphoreCount;
    const VkSemaphore*     pWaitSemaphores;
    uint32_t               bufferBindCount;
    const VkSparseBufferMemoryBindInfo* pBufferBinds;
    uint32_t               imageOpaqueBindCount;
    const VkSparseImageOpaqueMemoryBindInfo* pImageOpaqueBinds;
    uint32_t               imageBindCount;
    const VkSparseImageMemoryBindInfo* pImageBinds;
    uint32_t               signalSemaphoreCount;
    const VkSemaphore*     pSignalSemaphores;
} VkBindSparseInfo;

typedef struct {
    VkImageSubresourceLayers srcSubresource;
    VkOffset3D             srcOffset;
    VkImageSubresourceLayers dstSubresource;
    VkOffset3D             dstOffset;
    VkExtent3D             extent;
} VkImageCopy;

typedef struct {
    VkImageSubresourceLayers srcSubresource;
    VkOffset3D             srcOffsets[2];
    VkImageSubresourceLayers dstSubresource;
    VkOffset3D             dstOffsets[2];
} VkImageBlit;

typedef struct {
    VkDeviceSize           bufferOffset;
    uint32_t               bufferRowLength;
    uint32_t               bufferImageHeight;
    VkImageSubresourceLayers imageSubresource;
    VkOffset3D             imageOffset;
    VkExtent3D             imageExtent;
} VkBufferImageCopy;

typedef struct {
    VkImageSubresourceLayers srcSubresource;
    VkOffset3D             srcOffset;
    VkImageSubresourceLayers dstSubresource;
    VkOffset3D             dstOffset;
    VkExtent3D             extent;
} VkImageResolve;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkShaderModuleCreateFlags flags;
    size_t                 codeSize;
    const uint32_t*            pCode;
} VkShaderModuleCreateInfo;

typedef struct {
    uint32_t               binding;
    VkDescriptorType       descriptorType;
    uint32_t descriptorCount;
    VkShaderStageFlags     stageFlags;
    const VkSampler*       pImmutableSamplers;
} VkDescriptorSetLayoutBinding;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDescriptorSetLayoutCreateFlags    flags;
    uint32_t               bindingCount;
    const VkDescriptorSetLayoutBinding* pBindings;
} VkDescriptorSetLayoutCreateInfo;

typedef struct {
    VkDescriptorType       type;
    uint32_t               descriptorCount;
} VkDescriptorPoolSize;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDescriptorPoolCreateFlags  flags;
    uint32_t               maxSets;
    uint32_t               poolSizeCount;
    const VkDescriptorPoolSize* pPoolSizes;
} VkDescriptorPoolCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkDescriptorPool       descriptorPool;
    uint32_t               descriptorSetCount;
    const VkDescriptorSetLayout* pSetLayouts;
} VkDescriptorSetAllocateInfo;

typedef struct {
    uint32_t               constantID;
    uint32_t               offset;
    size_t                 size;
} VkSpecializationMapEntry;

typedef struct {
    uint32_t               mapEntryCount;
    const VkSpecializationMapEntry* pMapEntries;
    size_t                 dataSize;
    const void*            pData;
} VkSpecializationInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineShaderStageCreateFlags    flags;
    VkShaderStageFlagBits  stage;
    VkShaderModule         module;
    const char*            pName;
    const VkSpecializationInfo* pSpecializationInfo;
} VkPipelineShaderStageCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineCreateFlags  flags;
    VkPipelineShaderStageCreateInfo stage;
    VkPipelineLayout       layout;
    VkPipeline      basePipelineHandle;
    int32_t                basePipelineIndex;
} VkComputePipelineCreateInfo;

typedef struct {
    uint32_t               binding;
    uint32_t               stride;
    VkVertexInputRate      inputRate;
} VkVertexInputBindingDescription;

typedef struct {
    uint32_t               location;
    uint32_t               binding;
    VkFormat               format;
    uint32_t               offset;
} VkVertexInputAttributeDescription;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineVertexInputStateCreateFlags    flags;
    uint32_t               vertexBindingDescriptionCount;
    const VkVertexInputBindingDescription* pVertexBindingDescriptions;
    uint32_t               vertexAttributeDescriptionCount;
    const VkVertexInputAttributeDescription* pVertexAttributeDescriptions;
} VkPipelineVertexInputStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineInputAssemblyStateCreateFlags    flags;
    VkPrimitiveTopology    topology;
    VkBool32               primitiveRestartEnable;
} VkPipelineInputAssemblyStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineTessellationStateCreateFlags    flags;
    uint32_t               patchControlPoints;
} VkPipelineTessellationStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineViewportStateCreateFlags    flags;
    uint32_t               viewportCount;
    const VkViewport*      pViewports;
    uint32_t               scissorCount;
    const VkRect2D*        pScissors;
} VkPipelineViewportStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void* pNext;
    VkPipelineRasterizationStateCreateFlags    flags;
    VkBool32               depthClampEnable;
    VkBool32               rasterizerDiscardEnable;
    VkPolygonMode          polygonMode;
    VkCullModeFlags        cullMode;
    VkFrontFace            frontFace;
    VkBool32               depthBiasEnable;
    float                  depthBiasConstantFactor;
    float                  depthBiasClamp;
    float                  depthBiasSlopeFactor;
    float                  lineWidth;
} VkPipelineRasterizationStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineMultisampleStateCreateFlags    flags;
    VkSampleCountFlagBits  rasterizationSamples;
    VkBool32               sampleShadingEnable;
    float                  minSampleShading;
    const VkSampleMask*    pSampleMask;
    VkBool32               alphaToCoverageEnable;
    VkBool32               alphaToOneEnable;
} VkPipelineMultisampleStateCreateInfo;

typedef struct {
    VkBool32               blendEnable;
    VkBlendFactor          srcColorBlendFactor;
    VkBlendFactor          dstColorBlendFactor;
    VkBlendOp              colorBlendOp;
    VkBlendFactor          srcAlphaBlendFactor;
    VkBlendFactor          dstAlphaBlendFactor;
    VkBlendOp              alphaBlendOp;
    VkColorComponentFlags  colorWriteMask;
} VkPipelineColorBlendAttachmentState;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineColorBlendStateCreateFlags    flags;
    VkBool32               logicOpEnable;
    VkLogicOp              logicOp;
    uint32_t               attachmentCount;
    const VkPipelineColorBlendAttachmentState* pAttachments;
    float                  blendConstants[4];
} VkPipelineColorBlendStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineDynamicStateCreateFlags    flags;
    uint32_t               dynamicStateCount;
    const VkDynamicState*  pDynamicStates;
} VkPipelineDynamicStateCreateInfo;

typedef struct {
    VkStencilOp            failOp;
    VkStencilOp            passOp;
    VkStencilOp            depthFailOp;
    VkCompareOp            compareOp;
    uint32_t               compareMask;
    uint32_t               writeMask;
    uint32_t               reference;
} VkStencilOpState;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineDepthStencilStateCreateFlags    flags;
    VkBool32               depthTestEnable;
    VkBool32               depthWriteEnable;
    VkCompareOp            depthCompareOp;
    VkBool32               depthBoundsTestEnable;
    VkBool32               stencilTestEnable;
    VkStencilOpState       front;
    VkStencilOpState       back;
    float                  minDepthBounds;
    float                  maxDepthBounds;
} VkPipelineDepthStencilStateCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineCreateFlags  flags;
    uint32_t               stageCount;
    const VkPipelineShaderStageCreateInfo* pStages;
    const VkPipelineVertexInputStateCreateInfo* pVertexInputState;
    const VkPipelineInputAssemblyStateCreateInfo* pInputAssemblyState;
    const VkPipelineTessellationStateCreateInfo* pTessellationState;
    const VkPipelineViewportStateCreateInfo* pViewportState;
    const VkPipelineRasterizationStateCreateInfo* pRasterizationState;
    const VkPipelineMultisampleStateCreateInfo* pMultisampleState;
    const VkPipelineDepthStencilStateCreateInfo* pDepthStencilState;
    const VkPipelineColorBlendStateCreateInfo* pColorBlendState;
    const VkPipelineDynamicStateCreateInfo* pDynamicState;
    VkPipelineLayout       layout;
    VkRenderPass           renderPass;
    uint32_t               subpass;
    VkPipeline      basePipelineHandle;
    int32_t                basePipelineIndex;
} VkGraphicsPipelineCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineCacheCreateFlags    flags;
    size_t                 initialDataSize;
    const void*            pInitialData;
} VkPipelineCacheCreateInfo;

typedef struct {
    VkShaderStageFlags     stageFlags;
    uint32_t               offset;
    uint32_t               size;
} VkPushConstantRange;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkPipelineLayoutCreateFlags    flags;
    uint32_t               setLayoutCount;
    const VkDescriptorSetLayout* pSetLayouts;
    uint32_t               pushConstantRangeCount;
    const VkPushConstantRange* pPushConstantRanges;
} VkPipelineLayoutCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkSamplerCreateFlags   flags;
    VkFilter               magFilter;
    VkFilter               minFilter;
    VkSamplerMipmapMode    mipmapMode;
    VkSamplerAddressMode   addressModeU;
    VkSamplerAddressMode   addressModeV;
    VkSamplerAddressMode   addressModeW;
    float                  mipLodBias;
    VkBool32               anisotropyEnable;
    float                  maxAnisotropy;
    VkBool32               compareEnable;
    VkCompareOp            compareOp;
    float                  minLod;
    float                  maxLod;
    VkBorderColor          borderColor;
    VkBool32               unnormalizedCoordinates;
} VkSamplerCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkCommandPoolCreateFlags   flags;
    uint32_t               queueFamilyIndex;
} VkCommandPoolCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkCommandPool          commandPool;
    VkCommandBufferLevel   level;
    uint32_t               commandBufferCount;
} VkCommandBufferAllocateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkRenderPass    renderPass;
    uint32_t               subpass;
    VkFramebuffer   framebuffer;
    VkBool32               occlusionQueryEnable;
    VkQueryControlFlags    queryFlags;
    VkQueryPipelineStatisticFlags pipelineStatistics;
} VkCommandBufferInheritanceInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkCommandBufferUsageFlags  flags;
    const VkCommandBufferInheritanceInfo*       pInheritanceInfo;
} VkCommandBufferBeginInfo;

typedef union {
    float                  float32[4];
    int32_t                int32[4];
    uint32_t               uint32[4];
} VkClearColorValue;

typedef struct {
    float                  depth;
    uint32_t               stencil;
} VkClearDepthStencilValue;

typedef union {
    VkClearColorValue      color;
    VkClearDepthStencilValue depthStencil;
} VkClearValue;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkRenderPass           renderPass;
    VkFramebuffer          framebuffer;
    VkRect2D               renderArea;
    uint32_t               clearValueCount;
    const VkClearValue*    pClearValues;
} VkRenderPassBeginInfo;

typedef struct {
    VkImageAspectFlags     aspectMask;
    uint32_t               colorAttachment;
    VkClearValue           clearValue;
} VkClearAttachment;

typedef struct {
    VkAttachmentDescriptionFlags flags;
    VkFormat               format;
    VkSampleCountFlagBits  samples;
    VkAttachmentLoadOp     loadOp;
    VkAttachmentStoreOp    storeOp;
    VkAttachmentLoadOp     stencilLoadOp;
    VkAttachmentStoreOp    stencilStoreOp;
    VkImageLayout          initialLayout;
    VkImageLayout          finalLayout;
} VkAttachmentDescription;

typedef struct {
    uint32_t               attachment;
    VkImageLayout          layout;
} VkAttachmentReference;

typedef struct {
    VkSubpassDescriptionFlags flags;
    VkPipelineBindPoint    pipelineBindPoint;
    uint32_t               inputAttachmentCount;
    const VkAttachmentReference* pInputAttachments;
    uint32_t               colorAttachmentCount;
    const VkAttachmentReference* pColorAttachments;
    const VkAttachmentReference* pResolveAttachments;
    const VkAttachmentReference* pDepthStencilAttachment;
    uint32_t               preserveAttachmentCount;
    const uint32_t* pPreserveAttachments;
} VkSubpassDescription;

typedef struct {
    uint32_t               srcSubpass;
    uint32_t               dstSubpass;
    VkPipelineStageFlags   srcStageMask;
    VkPipelineStageFlags   dstStageMask;
    VkAccessFlags          srcAccessMask;
    VkAccessFlags          dstAccessMask;
    VkDependencyFlags      dependencyFlags;
} VkSubpassDependency;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkRenderPassCreateFlags    flags;
    uint32_t   attachmentCount;
    const VkAttachmentDescription* pAttachments;
    uint32_t               subpassCount;
    const VkSubpassDescription* pSubpasses;
    uint32_t       dependencyCount;
    const VkSubpassDependency* pDependencies;
} VkRenderPassCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkEventCreateFlags     flags;
} VkEventCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkFenceCreateFlags     flags;
} VkFenceCreateInfo;

typedef struct {
    VkBool32               residencyStandard2DBlockShape;
    VkBool32               residencyStandard2DMultisampleBlockShape;
    VkBool32               residencyStandard3DBlockShape;
    VkBool32               residencyAlignedMipSize;
    VkBool32               residencyNonResidentStrict;
} VkPhysicalDeviceSparseProperties;

typedef struct {
    uint32_t               maxImageDimension1D;
    uint32_t               maxImageDimension2D;
    uint32_t               maxImageDimension3D;
    uint32_t               maxImageDimensionCube;
    uint32_t               maxImageArrayLayers;
    uint32_t               maxTexelBufferElements;
    uint32_t               maxUniformBufferRange;
    uint32_t               maxStorageBufferRange;
    uint32_t               maxPushConstantsSize;
    uint32_t               maxMemoryAllocationCount;
    uint32_t               maxSamplerAllocationCount;
    VkDeviceSize           bufferImageGranularity;
    VkDeviceSize           sparseAddressSpaceSize;
    uint32_t               maxBoundDescriptorSets;
    uint32_t               maxPerStageDescriptorSamplers;
    uint32_t               maxPerStageDescriptorUniformBuffers;
    uint32_t               maxPerStageDescriptorStorageBuffers;
    uint32_t               maxPerStageDescriptorSampledImages;
    uint32_t               maxPerStageDescriptorStorageImages;
    uint32_t               maxPerStageDescriptorInputAttachments;
    uint32_t               maxPerStageResources;
    uint32_t               maxDescriptorSetSamplers;
    uint32_t               maxDescriptorSetUniformBuffers;
    uint32_t               maxDescriptorSetUniformBuffersDynamic;
    uint32_t               maxDescriptorSetStorageBuffers;
    uint32_t               maxDescriptorSetStorageBuffersDynamic;
    uint32_t               maxDescriptorSetSampledImages;
    uint32_t               maxDescriptorSetStorageImages;
    uint32_t               maxDescriptorSetInputAttachments;
    uint32_t               maxVertexInputAttributes;
    uint32_t               maxVertexInputBindings;
    uint32_t               maxVertexInputAttributeOffset;
    uint32_t               maxVertexInputBindingStride;
    uint32_t               maxVertexOutputComponents;
    uint32_t               maxTessellationGenerationLevel;
    uint32_t               maxTessellationPatchSize;
    uint32_t               maxTessellationControlPerVertexInputComponents;
    uint32_t               maxTessellationControlPerVertexOutputComponents;
    uint32_t               maxTessellationControlPerPatchOutputComponents;
    uint32_t               maxTessellationControlTotalOutputComponents;
    uint32_t               maxTessellationEvaluationInputComponents;
    uint32_t               maxTessellationEvaluationOutputComponents;
    uint32_t               maxGeometryShaderInvocations;
    uint32_t               maxGeometryInputComponents;
    uint32_t               maxGeometryOutputComponents;
    uint32_t               maxGeometryOutputVertices;
    uint32_t               maxGeometryTotalOutputComponents;
    uint32_t               maxFragmentInputComponents;
    uint32_t               maxFragmentOutputAttachments;
    uint32_t               maxFragmentDualSrcAttachments;
    uint32_t               maxFragmentCombinedOutputResources;
    uint32_t               maxComputeSharedMemorySize;
    uint32_t               maxComputeWorkGroupCount[3];
    uint32_t               maxComputeWorkGroupInvocations;
    uint32_t               maxComputeWorkGroupSize[3];
    uint32_t               subPixelPrecisionBits;
    uint32_t               subTexelPrecisionBits;
    uint32_t               mipmapPrecisionBits;
    uint32_t               maxDrawIndexedIndexValue;
    uint32_t               maxDrawIndirectCount;
    float                  maxSamplerLodBias;
    float                  maxSamplerAnisotropy;
    uint32_t               maxViewports;
    uint32_t               maxViewportDimensions[2];
    float                  viewportBoundsRange[2];
    uint32_t               viewportSubPixelBits;
    size_t                 minMemoryMapAlignment;
    VkDeviceSize           minTexelBufferOffsetAlignment;
    VkDeviceSize           minUniformBufferOffsetAlignment;
    VkDeviceSize           minStorageBufferOffsetAlignment;
    int32_t                minTexelOffset;
    uint32_t               maxTexelOffset;
    int32_t                minTexelGatherOffset;
    uint32_t               maxTexelGatherOffset;
    float                  minInterpolationOffset;
    float                  maxInterpolationOffset;
    uint32_t               subPixelInterpolationOffsetBits;
    uint32_t               maxFramebufferWidth;
    uint32_t               maxFramebufferHeight;
    uint32_t               maxFramebufferLayers;
    VkSampleCountFlags     framebufferColorSampleCounts;
    VkSampleCountFlags     framebufferDepthSampleCounts;
    VkSampleCountFlags     framebufferStencilSampleCounts;
    VkSampleCountFlags     framebufferNoAttachmentsSampleCounts;
    uint32_t               maxColorAttachments;
    VkSampleCountFlags     sampledImageColorSampleCounts;
    VkSampleCountFlags     sampledImageIntegerSampleCounts;
    VkSampleCountFlags     sampledImageDepthSampleCounts;
    VkSampleCountFlags     sampledImageStencilSampleCounts;
    VkSampleCountFlags     storageImageSampleCounts;
    uint32_t               maxSampleMaskWords;
    VkBool32               timestampComputeAndGraphics;
    float                  timestampPeriod;
    uint32_t               maxClipDistances;
    uint32_t               maxCullDistances;
    uint32_t               maxCombinedClipAndCullDistances;
    uint32_t               discreteQueuePriorities;
    float                  pointSizeRange[2];
    float                  lineWidthRange[2];
    float                  pointSizeGranularity;
    float                  lineWidthGranularity;
    VkBool32               strictLines;
    VkBool32               standardSampleLocations;
    VkDeviceSize           optimalBufferCopyOffsetAlignment;
    VkDeviceSize           optimalBufferCopyRowPitchAlignment;
    VkDeviceSize           nonCoherentAtomSize;
} VkPhysicalDeviceLimits;

typedef struct {
    uint32_t       apiVersion;
    uint32_t       driverVersion;
    uint32_t       vendorID;
    uint32_t       deviceID;
    VkPhysicalDeviceType deviceType;
    char           deviceName[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
    uint8_t        pipelineCacheUUID[VK_UUID_SIZE];
    VkPhysicalDeviceLimits limits;
    VkPhysicalDeviceSparseProperties sparseProperties;
} VkPhysicalDeviceProperties;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkSemaphoreCreateFlags flags;
} VkSemaphoreCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkQueryPoolCreateFlags flags;
    VkQueryType            queryType;
    uint32_t               queryCount;
    VkQueryPipelineStatisticFlags pipelineStatistics;
} VkQueryPoolCreateInfo;

typedef struct {
    VkStructureType sType;
    const void*            pNext;
    VkFramebufferCreateFlags    flags;
    VkRenderPass           renderPass;
    uint32_t               attachmentCount;
    const VkImageView*     pAttachments;
    uint32_t               width;
    uint32_t               height;
    uint32_t               layers;
} VkFramebufferCreateInfo;

typedef struct {
    uint32_t               vertexCount;
    uint32_t               instanceCount;
    uint32_t               firstVertex;
    uint32_t               firstInstance;
} VkDrawIndirectCommand;

typedef struct {
    uint32_t               indexCount;
    uint32_t               instanceCount;
    uint32_t               firstIndex;
    int32_t                vertexOffset;
    uint32_t               firstInstance;
} VkDrawIndexedIndirectCommand;

typedef struct {
    uint32_t               x;
    uint32_t               y;
    uint32_t               z;
} VkDispatchIndirectCommand;

typedef struct {
    VkStructureType sType;
    const void* pNext;
    uint32_t       waitSemaphoreCount;
    const VkSemaphore*     pWaitSemaphores;
    const VkPipelineStageFlags*           pWaitDstStageMask;
    uint32_t       commandBufferCount;
    const VkCommandBuffer*     pCommandBuffers;
    uint32_t       signalSemaphoreCount;
    const VkSemaphore*     pSignalSemaphores;
} VkSubmitInfo;


/* Function prototypes. I'll bite the bullet and expect that
   vkCreateInstance(), vkEnumerateInstanceExtensionProperties() and
   vkEnumerateInstanceLayerProperties() functions can be loaded statically to
   avoid the need for a global flextVkInit() that needs to be called before
   everything else. */
void FLEXTVK_EXPORT flextVkInitInstance(VkInstance instance);


/* VK_VERSION_1_0 */

extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkAllocateCommandBuffers)(VkDevice, const VkCommandBufferAllocateInfo*, VkCommandBuffer*);
#define vkAllocateCommandBuffers flextvkAllocateCommandBuffers
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkAllocateDescriptorSets)(VkDevice, const VkDescriptorSetAllocateInfo*, VkDescriptorSet*);
#define vkAllocateDescriptorSets flextvkAllocateDescriptorSets
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkAllocateMemory)(VkDevice, const VkMemoryAllocateInfo*, const VkAllocationCallbacks*, VkDeviceMemory*);
#define vkAllocateMemory flextvkAllocateMemory
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkBeginCommandBuffer)(VkCommandBuffer, const VkCommandBufferBeginInfo*);
#define vkBeginCommandBuffer flextvkBeginCommandBuffer
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkBindBufferMemory)(VkDevice, VkBuffer, VkDeviceMemory, VkDeviceSize);
#define vkBindBufferMemory flextvkBindBufferMemory
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkBindImageMemory)(VkDevice, VkImage, VkDeviceMemory, VkDeviceSize);
#define vkBindImageMemory flextvkBindImageMemory
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBeginQuery)(VkCommandBuffer, VkQueryPool, uint32_t, VkQueryControlFlags);
#define vkCmdBeginQuery flextvkCmdBeginQuery
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBeginRenderPass)(VkCommandBuffer, const VkRenderPassBeginInfo*, VkSubpassContents);
#define vkCmdBeginRenderPass flextvkCmdBeginRenderPass
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindDescriptorSets)(VkCommandBuffer, VkPipelineBindPoint, VkPipelineLayout, uint32_t, uint32_t, const VkDescriptorSet*, uint32_t, const uint32_t*);
#define vkCmdBindDescriptorSets flextvkCmdBindDescriptorSets
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindIndexBuffer)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkIndexType);
#define vkCmdBindIndexBuffer flextvkCmdBindIndexBuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindPipeline)(VkCommandBuffer, VkPipelineBindPoint, VkPipeline);
#define vkCmdBindPipeline flextvkCmdBindPipeline
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBindVertexBuffers)(VkCommandBuffer, uint32_t, uint32_t, const VkBuffer*, const VkDeviceSize*);
#define vkCmdBindVertexBuffers flextvkCmdBindVertexBuffers
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdBlitImage)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageBlit*, VkFilter);
#define vkCmdBlitImage flextvkCmdBlitImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdClearAttachments)(VkCommandBuffer, uint32_t, const VkClearAttachment*, uint32_t, const VkClearRect*);
#define vkCmdClearAttachments flextvkCmdClearAttachments
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdClearColorImage)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearColorValue*, uint32_t, const VkImageSubresourceRange*);
#define vkCmdClearColorImage flextvkCmdClearColorImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdClearDepthStencilImage)(VkCommandBuffer, VkImage, VkImageLayout, const VkClearDepthStencilValue*, uint32_t, const VkImageSubresourceRange*);
#define vkCmdClearDepthStencilImage flextvkCmdClearDepthStencilImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyBuffer)(VkCommandBuffer, VkBuffer, VkBuffer, uint32_t, const VkBufferCopy*);
#define vkCmdCopyBuffer flextvkCmdCopyBuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyBufferToImage)(VkCommandBuffer, VkBuffer, VkImage, VkImageLayout, uint32_t, const VkBufferImageCopy*);
#define vkCmdCopyBufferToImage flextvkCmdCopyBufferToImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyImage)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageCopy*);
#define vkCmdCopyImage flextvkCmdCopyImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyImageToBuffer)(VkCommandBuffer, VkImage, VkImageLayout, VkBuffer, uint32_t, const VkBufferImageCopy*);
#define vkCmdCopyImageToBuffer flextvkCmdCopyImageToBuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdCopyQueryPoolResults)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t, VkBuffer, VkDeviceSize, VkDeviceSize, VkQueryResultFlags);
#define vkCmdCopyQueryPoolResults flextvkCmdCopyQueryPoolResults
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDispatch)(VkCommandBuffer, uint32_t, uint32_t, uint32_t);
#define vkCmdDispatch flextvkCmdDispatch
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDispatchIndirect)(VkCommandBuffer, VkBuffer, VkDeviceSize);
#define vkCmdDispatchIndirect flextvkCmdDispatchIndirect
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDraw)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t);
#define vkCmdDraw flextvkCmdDraw
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDrawIndexed)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t);
#define vkCmdDrawIndexed flextvkCmdDrawIndexed
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDrawIndexedIndirect)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t);
#define vkCmdDrawIndexedIndirect flextvkCmdDrawIndexedIndirect
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdDrawIndirect)(VkCommandBuffer, VkBuffer, VkDeviceSize, uint32_t, uint32_t);
#define vkCmdDrawIndirect flextvkCmdDrawIndirect
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdEndQuery)(VkCommandBuffer, VkQueryPool, uint32_t);
#define vkCmdEndQuery flextvkCmdEndQuery
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdEndRenderPass)(VkCommandBuffer);
#define vkCmdEndRenderPass flextvkCmdEndRenderPass
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdExecuteCommands)(VkCommandBuffer, uint32_t, const VkCommandBuffer*);
#define vkCmdExecuteCommands flextvkCmdExecuteCommands
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdFillBuffer)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, uint32_t);
#define vkCmdFillBuffer flextvkCmdFillBuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdNextSubpass)(VkCommandBuffer, VkSubpassContents);
#define vkCmdNextSubpass flextvkCmdNextSubpass
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdPipelineBarrier)(VkCommandBuffer, VkPipelineStageFlags, VkPipelineStageFlags, VkDependencyFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*);
#define vkCmdPipelineBarrier flextvkCmdPipelineBarrier
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdPushConstants)(VkCommandBuffer, VkPipelineLayout, VkShaderStageFlags, uint32_t, uint32_t, const void*);
#define vkCmdPushConstants flextvkCmdPushConstants
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdResetEvent)(VkCommandBuffer, VkEvent, VkPipelineStageFlags);
#define vkCmdResetEvent flextvkCmdResetEvent
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdResetQueryPool)(VkCommandBuffer, VkQueryPool, uint32_t, uint32_t);
#define vkCmdResetQueryPool flextvkCmdResetQueryPool
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdResolveImage)(VkCommandBuffer, VkImage, VkImageLayout, VkImage, VkImageLayout, uint32_t, const VkImageResolve*);
#define vkCmdResolveImage flextvkCmdResolveImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetBlendConstants)(VkCommandBuffer, const float [4]);
#define vkCmdSetBlendConstants flextvkCmdSetBlendConstants
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetDepthBias)(VkCommandBuffer, float, float, float);
#define vkCmdSetDepthBias flextvkCmdSetDepthBias
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetDepthBounds)(VkCommandBuffer, float, float);
#define vkCmdSetDepthBounds flextvkCmdSetDepthBounds
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetEvent)(VkCommandBuffer, VkEvent, VkPipelineStageFlags);
#define vkCmdSetEvent flextvkCmdSetEvent
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetLineWidth)(VkCommandBuffer, float);
#define vkCmdSetLineWidth flextvkCmdSetLineWidth
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetScissor)(VkCommandBuffer, uint32_t, uint32_t, const VkRect2D*);
#define vkCmdSetScissor flextvkCmdSetScissor
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetStencilCompareMask)(VkCommandBuffer, VkStencilFaceFlags, uint32_t);
#define vkCmdSetStencilCompareMask flextvkCmdSetStencilCompareMask
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetStencilReference)(VkCommandBuffer, VkStencilFaceFlags, uint32_t);
#define vkCmdSetStencilReference flextvkCmdSetStencilReference
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetStencilWriteMask)(VkCommandBuffer, VkStencilFaceFlags, uint32_t);
#define vkCmdSetStencilWriteMask flextvkCmdSetStencilWriteMask
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdSetViewport)(VkCommandBuffer, uint32_t, uint32_t, const VkViewport*);
#define vkCmdSetViewport flextvkCmdSetViewport
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdUpdateBuffer)(VkCommandBuffer, VkBuffer, VkDeviceSize, VkDeviceSize, const void*);
#define vkCmdUpdateBuffer flextvkCmdUpdateBuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdWaitEvents)(VkCommandBuffer, uint32_t, const VkEvent*, VkPipelineStageFlags, VkPipelineStageFlags, uint32_t, const VkMemoryBarrier*, uint32_t, const VkBufferMemoryBarrier*, uint32_t, const VkImageMemoryBarrier*);
#define vkCmdWaitEvents flextvkCmdWaitEvents
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkCmdWriteTimestamp)(VkCommandBuffer, VkPipelineStageFlagBits, VkQueryPool, uint32_t);
#define vkCmdWriteTimestamp flextvkCmdWriteTimestamp
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateBuffer)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*);
#define vkCreateBuffer flextvkCreateBuffer
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateBufferView)(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*);
#define vkCreateBufferView flextvkCreateBufferView
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateCommandPool)(VkDevice, const VkCommandPoolCreateInfo*, const VkAllocationCallbacks*, VkCommandPool*);
#define vkCreateCommandPool flextvkCreateCommandPool
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateComputePipelines)(VkDevice, VkPipelineCache, uint32_t, const VkComputePipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*);
#define vkCreateComputePipelines flextvkCreateComputePipelines
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateDescriptorPool)(VkDevice, const VkDescriptorPoolCreateInfo*, const VkAllocationCallbacks*, VkDescriptorPool*);
#define vkCreateDescriptorPool flextvkCreateDescriptorPool
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateDescriptorSetLayout)(VkDevice, const VkDescriptorSetLayoutCreateInfo*, const VkAllocationCallbacks*, VkDescriptorSetLayout*);
#define vkCreateDescriptorSetLayout flextvkCreateDescriptorSetLayout
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateDevice)(VkPhysicalDevice, const VkDeviceCreateInfo*, const VkAllocationCallbacks*, VkDevice*);
#define vkCreateDevice flextvkCreateDevice
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateEvent)(VkDevice, const VkEventCreateInfo*, const VkAllocationCallbacks*, VkEvent*);
#define vkCreateEvent flextvkCreateEvent
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateFence)(VkDevice, const VkFenceCreateInfo*, const VkAllocationCallbacks*, VkFence*);
#define vkCreateFence flextvkCreateFence
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateFramebuffer)(VkDevice, const VkFramebufferCreateInfo*, const VkAllocationCallbacks*, VkFramebuffer*);
#define vkCreateFramebuffer flextvkCreateFramebuffer
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateGraphicsPipelines)(VkDevice, VkPipelineCache, uint32_t, const VkGraphicsPipelineCreateInfo*, const VkAllocationCallbacks*, VkPipeline*);
#define vkCreateGraphicsPipelines flextvkCreateGraphicsPipelines
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateImage)(VkDevice, const VkImageCreateInfo*, const VkAllocationCallbacks*, VkImage*);
#define vkCreateImage flextvkCreateImage
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateImageView)(VkDevice, const VkImageViewCreateInfo*, const VkAllocationCallbacks*, VkImageView*);
#define vkCreateImageView flextvkCreateImageView
VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo*, const VkAllocationCallbacks*, VkInstance*);
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreatePipelineCache)(VkDevice, const VkPipelineCacheCreateInfo*, const VkAllocationCallbacks*, VkPipelineCache*);
#define vkCreatePipelineCache flextvkCreatePipelineCache
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreatePipelineLayout)(VkDevice, const VkPipelineLayoutCreateInfo*, const VkAllocationCallbacks*, VkPipelineLayout*);
#define vkCreatePipelineLayout flextvkCreatePipelineLayout
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateQueryPool)(VkDevice, const VkQueryPoolCreateInfo*, const VkAllocationCallbacks*, VkQueryPool*);
#define vkCreateQueryPool flextvkCreateQueryPool
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateRenderPass)(VkDevice, const VkRenderPassCreateInfo*, const VkAllocationCallbacks*, VkRenderPass*);
#define vkCreateRenderPass flextvkCreateRenderPass
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateSampler)(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*);
#define vkCreateSampler flextvkCreateSampler
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateSemaphore)(VkDevice, const VkSemaphoreCreateInfo*, const VkAllocationCallbacks*, VkSemaphore*);
#define vkCreateSemaphore flextvkCreateSemaphore
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkCreateShaderModule)(VkDevice, const VkShaderModuleCreateInfo*, const VkAllocationCallbacks*, VkShaderModule*);
#define vkCreateShaderModule flextvkCreateShaderModule
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyBuffer)(VkDevice, VkBuffer, const VkAllocationCallbacks*);
#define vkDestroyBuffer flextvkDestroyBuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyBufferView)(VkDevice, VkBufferView, const VkAllocationCallbacks*);
#define vkDestroyBufferView flextvkDestroyBufferView
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyCommandPool)(VkDevice, VkCommandPool, const VkAllocationCallbacks*);
#define vkDestroyCommandPool flextvkDestroyCommandPool
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyDescriptorPool)(VkDevice, VkDescriptorPool, const VkAllocationCallbacks*);
#define vkDestroyDescriptorPool flextvkDestroyDescriptorPool
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyDescriptorSetLayout)(VkDevice, VkDescriptorSetLayout, const VkAllocationCallbacks*);
#define vkDestroyDescriptorSetLayout flextvkDestroyDescriptorSetLayout
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyDevice)(VkDevice, const VkAllocationCallbacks*);
#define vkDestroyDevice flextvkDestroyDevice
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyEvent)(VkDevice, VkEvent, const VkAllocationCallbacks*);
#define vkDestroyEvent flextvkDestroyEvent
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyFence)(VkDevice, VkFence, const VkAllocationCallbacks*);
#define vkDestroyFence flextvkDestroyFence
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyFramebuffer)(VkDevice, VkFramebuffer, const VkAllocationCallbacks*);
#define vkDestroyFramebuffer flextvkDestroyFramebuffer
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyImage)(VkDevice, VkImage, const VkAllocationCallbacks*);
#define vkDestroyImage flextvkDestroyImage
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyImageView)(VkDevice, VkImageView, const VkAllocationCallbacks*);
#define vkDestroyImageView flextvkDestroyImageView
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyInstance)(VkInstance, const VkAllocationCallbacks*);
#define vkDestroyInstance flextvkDestroyInstance
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyPipeline)(VkDevice, VkPipeline, const VkAllocationCallbacks*);
#define vkDestroyPipeline flextvkDestroyPipeline
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyPipelineCache)(VkDevice, VkPipelineCache, const VkAllocationCallbacks*);
#define vkDestroyPipelineCache flextvkDestroyPipelineCache
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyPipelineLayout)(VkDevice, VkPipelineLayout, const VkAllocationCallbacks*);
#define vkDestroyPipelineLayout flextvkDestroyPipelineLayout
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyQueryPool)(VkDevice, VkQueryPool, const VkAllocationCallbacks*);
#define vkDestroyQueryPool flextvkDestroyQueryPool
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyRenderPass)(VkDevice, VkRenderPass, const VkAllocationCallbacks*);
#define vkDestroyRenderPass flextvkDestroyRenderPass
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroySampler)(VkDevice, VkSampler, const VkAllocationCallbacks*);
#define vkDestroySampler flextvkDestroySampler
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroySemaphore)(VkDevice, VkSemaphore, const VkAllocationCallbacks*);
#define vkDestroySemaphore flextvkDestroySemaphore
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkDestroyShaderModule)(VkDevice, VkShaderModule, const VkAllocationCallbacks*);
#define vkDestroyShaderModule flextvkDestroyShaderModule
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkDeviceWaitIdle)(VkDevice);
#define vkDeviceWaitIdle flextvkDeviceWaitIdle
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEndCommandBuffer)(VkCommandBuffer);
#define vkEndCommandBuffer flextvkEndCommandBuffer
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEnumerateDeviceExtensionProperties)(VkPhysicalDevice, const char*, uint32_t*, VkExtensionProperties*);
#define vkEnumerateDeviceExtensionProperties flextvkEnumerateDeviceExtensionProperties
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEnumerateDeviceLayerProperties)(VkPhysicalDevice, uint32_t*, VkLayerProperties*);
#define vkEnumerateDeviceLayerProperties flextvkEnumerateDeviceLayerProperties
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char*, uint32_t*, VkExtensionProperties*);
VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t*, VkLayerProperties*);
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkEnumeratePhysicalDevices)(VkInstance, uint32_t*, VkPhysicalDevice*);
#define vkEnumeratePhysicalDevices flextvkEnumeratePhysicalDevices
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkFlushMappedMemoryRanges)(VkDevice, uint32_t, const VkMappedMemoryRange*);
#define vkFlushMappedMemoryRanges flextvkFlushMappedMemoryRanges
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkFreeCommandBuffers)(VkDevice, VkCommandPool, uint32_t, const VkCommandBuffer*);
#define vkFreeCommandBuffers flextvkFreeCommandBuffers
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkFreeDescriptorSets)(VkDevice, VkDescriptorPool, uint32_t, const VkDescriptorSet*);
#define vkFreeDescriptorSets flextvkFreeDescriptorSets
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkFreeMemory)(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*);
#define vkFreeMemory flextvkFreeMemory
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetBufferMemoryRequirements)(VkDevice, VkBuffer, VkMemoryRequirements*);
#define vkGetBufferMemoryRequirements flextvkGetBufferMemoryRequirements
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetDeviceMemoryCommitment)(VkDevice, VkDeviceMemory, VkDeviceSize*);
#define vkGetDeviceMemoryCommitment flextvkGetDeviceMemoryCommitment
extern FLEXTVK_EXPORT PFN_vkVoidFunction(VKAPI_PTR *flextvkGetDeviceProcAddr)(VkDevice, const char*);
#define vkGetDeviceProcAddr flextvkGetDeviceProcAddr
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetDeviceQueue)(VkDevice, uint32_t, uint32_t, VkQueue*);
#define vkGetDeviceQueue flextvkGetDeviceQueue
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetEventStatus)(VkDevice, VkEvent);
#define vkGetEventStatus flextvkGetEventStatus
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetFenceStatus)(VkDevice, VkFence);
#define vkGetFenceStatus flextvkGetFenceStatus
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetImageMemoryRequirements)(VkDevice, VkImage, VkMemoryRequirements*);
#define vkGetImageMemoryRequirements flextvkGetImageMemoryRequirements
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetImageSparseMemoryRequirements)(VkDevice, VkImage, uint32_t*, VkSparseImageMemoryRequirements*);
#define vkGetImageSparseMemoryRequirements flextvkGetImageSparseMemoryRequirements
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetImageSubresourceLayout)(VkDevice, VkImage, const VkImageSubresource*, VkSubresourceLayout*);
#define vkGetImageSubresourceLayout flextvkGetImageSubresourceLayout
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance, const char*);
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceFeatures)(VkPhysicalDevice, VkPhysicalDeviceFeatures*);
#define vkGetPhysicalDeviceFeatures flextvkGetPhysicalDeviceFeatures
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceFormatProperties)(VkPhysicalDevice, VkFormat, VkFormatProperties*);
#define vkGetPhysicalDeviceFormatProperties flextvkGetPhysicalDeviceFormatProperties
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetPhysicalDeviceImageFormatProperties)(VkPhysicalDevice, VkFormat, VkImageType, VkImageTiling, VkImageUsageFlags, VkImageCreateFlags, VkImageFormatProperties*);
#define vkGetPhysicalDeviceImageFormatProperties flextvkGetPhysicalDeviceImageFormatProperties
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceMemoryProperties)(VkPhysicalDevice, VkPhysicalDeviceMemoryProperties*);
#define vkGetPhysicalDeviceMemoryProperties flextvkGetPhysicalDeviceMemoryProperties
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceProperties)(VkPhysicalDevice, VkPhysicalDeviceProperties*);
#define vkGetPhysicalDeviceProperties flextvkGetPhysicalDeviceProperties
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceQueueFamilyProperties)(VkPhysicalDevice, uint32_t*, VkQueueFamilyProperties*);
#define vkGetPhysicalDeviceQueueFamilyProperties flextvkGetPhysicalDeviceQueueFamilyProperties
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetPhysicalDeviceSparseImageFormatProperties)(VkPhysicalDevice, VkFormat, VkImageType, VkSampleCountFlagBits, VkImageUsageFlags, VkImageTiling, uint32_t*, VkSparseImageFormatProperties*);
#define vkGetPhysicalDeviceSparseImageFormatProperties flextvkGetPhysicalDeviceSparseImageFormatProperties
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetPipelineCacheData)(VkDevice, VkPipelineCache, size_t*, void*);
#define vkGetPipelineCacheData flextvkGetPipelineCacheData
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkGetQueryPoolResults)(VkDevice, VkQueryPool, uint32_t, uint32_t, size_t, void*, VkDeviceSize, VkQueryResultFlags);
#define vkGetQueryPoolResults flextvkGetQueryPoolResults
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkGetRenderAreaGranularity)(VkDevice, VkRenderPass, VkExtent2D*);
#define vkGetRenderAreaGranularity flextvkGetRenderAreaGranularity
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkInvalidateMappedMemoryRanges)(VkDevice, uint32_t, const VkMappedMemoryRange*);
#define vkInvalidateMappedMemoryRanges flextvkInvalidateMappedMemoryRanges
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkMapMemory)(VkDevice, VkDeviceMemory, VkDeviceSize, VkDeviceSize, VkMemoryMapFlags, void**);
#define vkMapMemory flextvkMapMemory
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkMergePipelineCaches)(VkDevice, VkPipelineCache, uint32_t, const VkPipelineCache*);
#define vkMergePipelineCaches flextvkMergePipelineCaches
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkQueueBindSparse)(VkQueue, uint32_t, const VkBindSparseInfo*, VkFence);
#define vkQueueBindSparse flextvkQueueBindSparse
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkQueueSubmit)(VkQueue, uint32_t, const VkSubmitInfo*, VkFence);
#define vkQueueSubmit flextvkQueueSubmit
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkQueueWaitIdle)(VkQueue);
#define vkQueueWaitIdle flextvkQueueWaitIdle
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetCommandBuffer)(VkCommandBuffer, VkCommandBufferResetFlags);
#define vkResetCommandBuffer flextvkResetCommandBuffer
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetCommandPool)(VkDevice, VkCommandPool, VkCommandPoolResetFlags);
#define vkResetCommandPool flextvkResetCommandPool
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetDescriptorPool)(VkDevice, VkDescriptorPool, VkDescriptorPoolResetFlags);
#define vkResetDescriptorPool flextvkResetDescriptorPool
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetEvent)(VkDevice, VkEvent);
#define vkResetEvent flextvkResetEvent
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkResetFences)(VkDevice, uint32_t, const VkFence*);
#define vkResetFences flextvkResetFences
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkSetEvent)(VkDevice, VkEvent);
#define vkSetEvent flextvkSetEvent
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkUnmapMemory)(VkDevice, VkDeviceMemory);
#define vkUnmapMemory flextvkUnmapMemory
extern FLEXTVK_EXPORT void(VKAPI_PTR *flextvkUpdateDescriptorSets)(VkDevice, uint32_t, const VkWriteDescriptorSet*, uint32_t, const VkCopyDescriptorSet*);
#define vkUpdateDescriptorSets flextvkUpdateDescriptorSets
extern FLEXTVK_EXPORT VkResult(VKAPI_PTR *flextvkWaitForFences)(VkDevice, uint32_t, const VkFence*, VkBool32, uint64_t);
#define vkWaitForFences flextvkWaitForFences

#endif

#ifdef __cplusplus
}
#endif

#endif
