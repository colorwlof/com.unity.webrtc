#include "pch.h"
#include "../GraphicsDeviceTestBase.h"
#include "../WebRTCPlugin/GraphicsDevice/ITexture2D.h"
#include "../WebRTCPlugin/Codec/EncoderFactory.h"
#include "../WebRTCPlugin/Codec/IEncoder.h"

namespace unity
{
namespace webrtc
{
    
class NvEncoderTest : public GraphicsDeviceTestBase
{
protected:
    std::unique_ptr<IEncoder> encoder_;

    void SetUp() override {
        GraphicsDeviceTestBase::SetUp();
        EXPECT_NE(nullptr, m_device);

        const auto width = 256;
        const auto height = 256;
        encoder_ = EncoderFactory::GetInstance().Init(width, height, m_device, m_encoderType);
        EXPECT_NE(nullptr, encoder_);
    }
    void TearDown() override {
        encoder_.reset();
        GraphicsDeviceTestBase::TearDown();
    }
};
TEST_P(NvEncoderTest, IsSupported) {
    EXPECT_TRUE(encoder_->IsSupported());
}
/*
TEST_P(NvEncoderTest, InitV) {
//    EXPECT_NO_THROW(encoder_->InitV());
}
*/
TEST_P(NvEncoderTest, UpdateSettings) {
//    EXPECT_NO_THROW(encoder_->InitV());
    EXPECT_NO_THROW(encoder_->UpdateSettings());
}

TEST_P(NvEncoderTest, EncodeFrame) {
    const auto width = 256;
    const auto height = 256;
//    const std::unique_ptr<ITexture2D> tex(m_device->CreateDefaultTextureV(width, height));
//    EXPECT_NO_THROW(encoder_->InitV());
//    EXPECT_TRUE(encoder_->EncodeFrame(tex->GetNativeTexturePtrV()));
    EXPECT_TRUE(encoder_->EncodeFrame(nullptr));
}

INSTANTIATE_TEST_CASE_P( GraphicsDeviceParameters, NvEncoderTest, testing::ValuesIn(VALUES_TEST_ENV));

} // end namespace webrtc
} // end namespace unity
