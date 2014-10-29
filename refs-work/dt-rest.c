	mmc@12550000 {
		num-slots = <1>;
		supports-highspeed;
		broken-cd;
		non-removable;
		card-detect-delay = <200>;
		vmmc-supply = <&vemmc_reg>;
		clock-frequency = <400000000>;
		samsung,dw-mshc-ciu-div = <0>;
		samsung,dw-mshc-sdr-timing = <2 3>;
		samsung,dw-mshc-ddr-timing = <1 2>;
		pinctrl-0 = <&sd4_clk &sd4_cmd &sd4_bus4 &sd4_bus8>;
		pinctrl-names = "default";
		status = "okay";

		slot@0 {
			reg = <0>;
			bus-width = <8>;
		};
	};

	serial@13800000 {
		status = "okay";
	};

	serial@13810000 {
		status = "okay";
	};

	serial@13820000 {
		status = "okay";
	};

	serial@13830000 {
		status = "okay";
	};

	i2c_ak8975: i2c-gpio-0 {
		compatible = "i2c-gpio";
		gpios = <&gpy2 4 0>, <&gpy2 5 0>;
		i2c-gpio,delay-us = <2>;
		#address-cells = <1>;
		#size-cells = <0>;
		status = "okay";

		ak8975@0c {
			compatible = "asahi-kasei,ak8975";
			reg = <0x0c>;
			gpios = <&gpj0 7 0>;
		};
	};

	i2c_cm36651: i2c-gpio-2 {
		compatible = "i2c-gpio";
		gpios = <&gpf0 0 1>, <&gpf0 1 1>;
		i2c-gpio,delay-us = <2>;
		#address-cells = <1>;
		#size-cells = <0>;

		cm36651@18 {
			compatible = "capella,cm36651";
			reg = <0x18>;
			interrupt-parent = <&gpx0>;
			interrupts = <2 2>;
			vled-supply = <&ps_als_reg>;
		};
	};

	spi_1: spi@13930000 {
		pinctrl-names = "default";
		pinctrl-0 = <&spi1_bus>;
		cs-gpios = <&gpb 5 0>;
		status = "okay";

		s5c73m3_spi: s5c73m3 {
			compatible = "samsung,s5c73m3";
			spi-max-frequency = <50000000>;
			reg = <0>;
			controller-data {
				samsung,spi-feedback-delay = <2>;
			};
		};
	};

	dsi_0: dsi@11C80000 {
		vddcore-supply = <&ldo8_reg>;
		vddio-supply = <&ldo10_reg>;
		samsung,pll-clock-frequency = <24000000>;
		status = "okay";

		ports {
			#address-cells = <1>;
			#size-cells = <0>;

			port@1 {
				reg = <1>;

				dsi_out: endpoint {
					remote-endpoint = <&dsi_in>;
					samsung,burst-clock-frequency = <500000000>;
					samsung,esc-clock-frequency = <20000000>;
				};
			};
		};

		panel@0 {
			compatible = "samsung,s6e8aa0";
			reg = <0>;
			vdd3-supply = <&lcd_vdd3_reg>;
			vci-supply = <&ldo25_reg>;
			reset-gpios = <&gpy4 5 0>;
			power-on-delay= <50>;
			reset-delay = <100>;
			init-delay = <100>;
			flip-horizontal;
			flip-vertical;
			panel-width-mm = <58>;
			panel-height-mm = <103>;

			display-timings {
				timing-0 {
					clock-frequency = <0>;
					hactive = <720>;
					vactive = <1280>;
					hfront-porch = <5>;
					hback-porch = <5>;
					hsync-len = <5>;
					vfront-porch = <13>;
					vback-porch = <1>;
					vsync-len = <2>;
				};
			};

			port {
				dsi_in: endpoint {
					remote-endpoint = <&dsi_out>;
				};
			};
		};
	};

	fimd@11c00000 {
		status = "okay";
	};

	camera: camera {
		pinctrl-0 = <&cam_port_a_clk_active &cam_port_b_clk_active>;
		pinctrl-names = "default";
		status = "okay";

		fimc_0: fimc@11800000 {
			status = "okay";
		};

		fimc_1: fimc@11810000 {
			status = "okay";
		};

		fimc_2: fimc@11820000 {
			status = "okay";
		};

		fimc_3: fimc@11830000 {
			status = "okay";
		};

		csis_0: csis@11880000 {
			status = "okay";
			vddcore-supply = <&ldo8_reg>;
			vddio-supply = <&ldo10_reg>;
			clock-frequency = <176000000>;

			/* Camera C (3) MIPI CSI-2 (CSIS0) */
			port@3 {
				reg = <3>;
				csis0_ep: endpoint {
					remote-endpoint = <&s5c73m3_ep>;
					data-lanes = <1 2 3 4>;
					samsung,csis-hs-settle = <12>;
				};
			};
		};

		csis_1: csis@11890000 {
			vddcore-supply = <&ldo8_reg>;
			vddio-supply = <&ldo10_reg>;
			clock-frequency = <160000000>;
			status = "okay";

			/* Camera D (4) MIPI CSI-2 (CSIS1) */
			port@4 {
				reg = <4>;
				csis1_ep: endpoint {
					remote-endpoint = <&is_s5k6a3_ep>;
					data-lanes = <1>;
					samsung,csis-hs-settle = <18>;
					samsung,csis-wclk;
				};
			};
		};

		fimc_lite_0: fimc-lite@12390000 {
			status = "okay";
		};

		fimc_lite_1: fimc-lite@123A0000 {
			status = "okay";
		};

		fimc-is@12000000 {
			pinctrl-0 = <&fimc_is_uart>;
			pinctrl-names = "default";
			status = "okay";

			i2c1_isp: i2c-isp@12140000 {
				pinctrl-0 = <&fimc_is_i2c1>;
				pinctrl-names = "default";

				s5k6a3@10 {
					compatible = "samsung,s5k6a3";
					reg = <0x10>;
					svdda-supply = <&cam_io_reg>;
					svddio-supply = <&ldo19_reg>;
					afvdd-supply = <&ldo19_reg>;
					clock-frequency = <24000000>;
					/* CAM_B_CLKOUT */
					clocks = <&camera 1>;
					clock-names = "extclk";
					samsung,camclk-out = <1>;
					gpios = <&gpm1 6 0>;

					port {
						is_s5k6a3_ep: endpoint {
							remote-endpoint = <&csis1_ep>;
							data-lanes = <1>;
						};
					};
				};
			};
		};
	};

	exynos-usbphy@125B0000 {
		status = "okay";
	};

	hsotg@12480000 {
		vusb_d-supply = <&ldo15_reg>;
		vusb_a-supply = <&ldo12_reg>;
		status = "okay";
	};

	thermistor-ap@0 {
		compatible = "ntc,ncp15wb473";
		pullup-uv = <1800000>;	 /* VCC_1.8V_AP */
		pullup-ohm = <100000>;	 /* 100K */
		pulldown-ohm = <100000>; /* 100K */
		io-channels = <&adc 1>;  /* AP temperature */
	};

	thermistor-battery@1 {
		compatible = "ntc,ncp15wb473";
		pullup-uv = <1800000>;	 /* VCC_1.8V_AP */
		pullup-ohm = <100000>;	 /* 100K */
		pulldown-ohm = <100000>; /* 100K */
		io-channels = <&adc 2>;  /* Battery temperature */
	};
};
