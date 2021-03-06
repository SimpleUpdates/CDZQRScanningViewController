Pod::Spec.new do |s|
  s.name         = 'CDZQRScanningViewController'
  s.version      = '1.0.7.5'
  s.summary      = 'Easy QR code scanning on iOS 7.'
  s.homepage     = 'https://github.com/cdzombak/CDZQRScanningViewController'
  s.license      = 'MIT'
  s.author       = { 'Chris Dzombak' => 'chris@chrisdzombak.net' }

  s.source       = { :git => 'https://github.com/OliverLetterer/CDZQRScanningViewController.git', :tag => s.version.to_s }
  s.platform     = :ios, '7.0'

  s.source_files = '*.{h,m}'
  s.public_header_files = 'CDZQRScanningViewController.h'
  s.frameworks   = ['AVFoundation', 'UIKit']
  s.requires_arc = true
end
