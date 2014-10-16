/* Víðir Alexander Jónsson (fractalhemispheres@gmail.com) 2014 */

/* Board file to device tree migration for Samsung's UNIVERSAL5420 board */

/* I am by no means a programming expert. Board files and device trees are not */
/* easy for me to understand but I am slowly getting the hang of it. */

/* There is already a device tree for a similar board, SMDK5420, but it is not completely */
/* accurate for the UNIVERSAL5420 which is found in several tablets and smartphones from Samsung. */
/* This is an attempt at completing the device tree based on its board files from the 3.4 kernel */
/* and the official Linux Documentation for the device tree. */

/* The 'exynos5420-universal5420.dts' file is still mostly a copy of the smdk5420 device tree. */
/* As soon as something here gets completed I will copy it over to the .dts file. */

/* Hopefully this porting effort will be able to produce a working device tree */
/* for the UNIVERSAL5420 so that we can finally get rid of those ugly board files. */


/* mfd */
/* MAX77803 */
max77803@?? {
	compatible = "maxim,max77803";
	interrupt-parent = <>;
	interrupts = <>;
	reg = <>;
	#address-cells = <>;
	#size-cells = <>;

	/* Based on information from board-universal5420-mfd.c: */
	regulators {
		safout1@??? {
			compatible = "safeout1", "safeout1,range";
			regulator-name = "ESAFEOUT1";
			regulator-always-on = <0>;
			regulator-boot-on = <1>;
			regulator-state-mem {
				enabled = <1>;
			};	
		};

		safeout2@??? {
			compatible = "safeout2", "safeout2,range";
			regulator-name = "ESAFEOUT2";
			regulator-always-on = <0>;
			regulator-boot-on = <0>;
			regulator-state-mem {
				enabled = <1>;
			};
		};

		charger-manager@0 {
			compatible = "charger-manager", "vinchg1";
			regulator-name = "CHARGER";
			regulator-min-microvolt= <60000>;
			regulator-max-microvolt = <2580000>;
			regulator-boot-on = <1>;
			regulator-always-on;
		};

		leds-sec1@??? {
			compatible = "leds-sec1";
		};
			/*
			#ifdef CONFIG_LEDS_MAX77803
			static struct max77803_led_platform_data max77803_led_pdata = {

				.num_leds = 2,

				.leds[0].name = "leds-sec1",
				.leds[0].id = MAX77803_FLASH_LED_1,
				.leds[0].timer = MAX77803_FLASH_TIME_187P5MS,
				.leds[0].timer_mode = MAX77803_TIMER_MODE_MAX_TIMER,
				.leds[0].cntrl_mode = MAX77803_LED_CTRL_BY_FLASHSTB,
			#if defined(CONFIG_MACH_V1A) || defined(CONFIG_MACH_N1A) || defined(CONFIG_N2A)
				.leds[0].brightness = 0x32, // Max77888 : 19.53mA+0x32*19.53 = 996.03 mA
			#else
				.leds[0].brightness = 0x3D,
		    	//.leds[0].brightness = 0x1E,
			#endif

				.leds[1].name = "torch-sec1",
				.leds[1].id = MAX77803_TORCH_LED_1,
				.leds[1].cntrl_mode = MAX77803_LED_CTRL_BY_FLASHSTB,
				.leds[1].brightness = 0x06,
			};
			*/

		torch-sec1@??? {
			compatible = "torch-sec1";
		};

		rtc@c {
			reg = <0xc>;
		};
	};
};



/* Wolfson WM5102 Arizona codec. */
/* The following was copied straight from the Documentation/devicetree/bindings/mfd/arizona.txt */
/* More information needs to be gathered from board files such as board-universal5420-audio-w.c */
	codec: wm5102@1a {
			compatible = "wlf,wm5102";
			reg = <0x1a>;
			interrupts = <347>;
			interrupt-controller;
			#interrupt-cells = <2>;
        		interrupt-parent = <&gic>;

			gpio-controller;
			#gpio-cells = <2>;

			wlf,gpio-defaults = <
				0xffffffff /* AIF1TXLRCLK */
				0xffffffff
				0xffffffff
				0xffffffff
				0xffffffff
			>;
		};

/* This seems to be there as well according to board-universal5420-audio.c */
		
		wm8994 {
			compatible = "wlf,wm8994";
			/* samsung-universal-pcm (not sure what this is yet) */
		};
	};
}



/* Bluetooth stuff. Not much at the moment. */
/* See: board-bluetooth-bcm4339.c */
		bcm4339 {
			compatible = "brcm,bcm4339";
		};