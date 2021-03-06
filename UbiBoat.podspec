#
# Be sure to run `pod lib lint UbiBoat.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'UbiBoat'
  s.version          = '1.1.1'
  s.summary          = 'A short description of UbiBoat.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
test ubiboat ...test ubiboat ...test ubiboat ...test ubiboat ...
                       DESC

  s.homepage         = 'https://github.com/cs081/UbiBoat'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'cs081' => '447449914@qq.com' }
  s.source           = { :git => 'https://github.com/cs081/UbiBoat.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  #s.source_files = 'UbiBoat/Classes/**/*'
  s.source_files = "Framework/Ubiboat.framework/Headers","*.{h,m,plist}"
  s.ios.vendored_frameworks = 'Framework/Ubiboat.framework'#SDK相对本文件路径
  # s.resource_bundles = {
  #   'UbiBoat' => ['UbiBoat/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'AFNetworking', '~> 2.3'
  s.dependency 'BabyBluetooth'
end
