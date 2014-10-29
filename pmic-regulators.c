#include "exynos5420.dtsi"
#include "exynos5420-pinctrl.dtsi"

	hsi2c_3: i2c@12CD0000 {
		compatible = "samsung,exynos5-hsi2c";
		reg = <0x12CD0000 0x1000>;
		#address-cells = <1>;
		#size-cells = <0>;
		clocks = <&clock CLK_USI0>;
		clock-names = "hsi2c";
		pinctrl-0 = <&i2c3_hs_bus>;
		pinctrl-names = "default";
		interrupts = <0 63 0>;
		clock-frequency = <400000>;
		status = "okay";


		max77802@09 {
			compatible = "maxim,max77802";
			interrupt-parent = <&wakeup_eint>;
			interrupts = <26 0>;
			reg = <0x09>;
			#address-cells = <1>;
			#size-cells = <0>;

			regulators {
				max77802_buck1_reg: BUCK1 {
					regulator-compatible = "BUCK1";
					regulator-name = "vdd_mif";
					regulator-min-microvolt = <700000>;
					regulator-max-microvolt = <1300000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-valid-modes-mask {
						regulator-change-voltage;
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-state-uv = <1100000>;
						regulator-state-mode = "normal";
						regulator-state-disabled;
					};
					max77802,consumer-supplies = "vdd_mif";
				};

				max77802_buck2_reg: BUCK2 {
					regulator-compatible = "BUCK2";
					regulator-name = "vdd_arm";
					regulator-min-microvolt = <800000>;
					regulator-max-microvolt = <1500000>;
					regulator-apply-uV;
					regulator-always-on;
					regulator-boot-on;
					regulator-valid-modes-mask {
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-state-disabled;
					};
					max77802,consumer-supplies = "vdd_arm";
				};

				max77802_buck3_reg: BUCK3 {
					regulator-compatible = "BUCK3";
					regulator-name = "vdd_int";
					regulator-min-microvolt = <800000>;
					regulator-max-microvolt = <1400000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {
						regulator-change-voltage;
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-state-uv = <1100000>;
						regulator-state-mode = "normal";
						regulator-state-disabled;
					};
					max77802,consumer-supplies = "vdd_int";
				};

				max77802_buck4_reg: BUCK4 {
					regulator-compatible = "BUCK4";
					regulator-name = "vdd_g3d";
					regulator-min-microvolt = <700000>;
					regulator-max-microvolt = <1400000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {
						regulator-change-voltage;
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-state-uv = <1100000>;
						regulator-state-mode = "normal";
						regulator-state-disabled;
					};
					max77802,consumer-supplies = "vdd_g3d";
				};

				max77802_buck6_reg: BUCK6 {
					regulator-compatible = "BUCK6";
					regulator-name = "vdd_kfc";
					regulator-min-microvolt = <800000>;
					regulator-max-microvolt = <1500000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-valid-modes-mask {
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-state-disabled;
					};
					max77802,consumer-supplies = "vdd_kfc";
				};

				max77802_ldo2_reg: LDO2 {
					regulator-name ="vmem2_1.2v_ap";
					regulator-min-microvolt = <1200000>;
					regulator-max-microvolt = <1200000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-state-disabled;
						regulator-state-enabled;
					};
					max77802,consumer-supplies = "vmem2_1.2v_ap"; //or: regulator-consumer-supplies =
				};

				max77802_ldo3_reg: LDO3 {
					regulator-compatible = 	"vcc_1.8v_ap", "spi2.0", "wm5102-codec";
					regulator-name = "vcc_1.8v_ap";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vcc_1.8v_ap";
				};

				max77802_ldo4_reg: LDO4 {
					regulator-compatible = "vmmc2_2.8v_ap", "vqmmc,dw_mmc.2", "vqmmc", "dw_mmc.2";
					regulator-name = "vmmc2_2.8v_ap";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <2800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {
						regulator-change-voltage;
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vmmc2_2.8v_ap";
				};

				max77802_ldo5_reg: LDO5 {
					regulator-name = "vhsic_1.8v_ap";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vhsic_1.8v_ap";
				};

				max77802_ldo6_reg: LDO6 {
					regulator-name = "vxpll_1.8v_ap"
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vxpll_1.8v_ap";
				};

				max77802_ldo8_reg: LDO8 {
					regulator-name = "vmipi_1.0v_ap"
					regulator-min-microvolt = <1000000>;
					regulator-max-microvolt = <1000000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vmipi_1.0v_ap";
				};

				max77802_ldo9_reg: LDO9 {
					regulator-name = "vadc_1.8v";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vadc_1.8v";
				};

				max77802_ldo10_reg: LDO10 {
					regulator-name = "vmipi_1.8v_ap";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vmipi_1.0v_ap";
				};

				max77802_ldo11_reg: LDO11 {
					regulator-name = "vddq_pre_1.8v";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vddq_pre_1.8v";
				};

				max77802_ldo12_reg: LDO12 {
					regulator-name = "vuotg_3.0v_ap";
					regulator-min-microvolt = <3000000>;
					regulator-max-microvolt = <3000000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vuotg_3.0v_ap";
				};

				max77802_ldo14_reg: LDO14 {
					regulator-name = "vabb1_1.8v_ap";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vabb1_1.8v_ap";
				};

				max77802_ldo15_reg: LDO15 {
					regulator-name = "vhsic_1.0v_ap";
					regulator-min-microvolt = <1000000>;
					regulator-max-microvolt = <1000000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vhsic_1.0v_ap";
				};

				max77802_ldo17_reg: LDO17 {
					regulator-name = "vg3ds_1.0v_ap";
					regulator-min-microvolt = <1000000>;
					regulator-max-microvolt = <1000000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vg3ds_1.0v_ap";
				};
			
				max77802_ldo18_reg: LDO18 {
					regulator-name = "cam_isp_sensor_io_1.8v";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "cam_isp_sensor_io_1.8v";
				};
			
				max77802_ldo19_reg: LDO19 {
					regulator-name = "vt_cam_1.8v";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vt_cam_1.8v";
				};
			
				max77802_ldo23_reg: LDO23 {
					regulator-name = "key_led_3.3v";
					regulator-min-microvolt = <3300000>;
					regulator-max-microvolt = <3300000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "key_led_3.3v";
				};

				max77802_ldo24_reg: LDO24 {
					regulator-name = "cam_af_2.8v_pm";
					regulator-min-microvolt = <2800000>;
					regulator-max-microvolt = <2800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {
						regulator-change-voltage;	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "cam_af_2.8v_pm";
				};

				max77802_ldo25_reg: LDO25 {
					regulator-name = "vcc_3.3v_mhl";
					regulator-min-microvolt = <3300000>;
					regulator-max-microvolt = <3300000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vcc_3.3v_mhl";
				};

				max77802_ldo26reg: LDO26 {
					regulator-name = "vcc_3.0v_motor";
					regulator-min-microvolt = <3000000>;
					regulator-max-microvolt = <3000000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vcc_3.0v_motor";
				};

				max77802_ldo27_reg: LDO27 {
					regulator-name = "vsil_1.2a";
					regulator-min-microvolt = <1200000>;
					regulator-max-microvolt = <1200000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vsil_1.2a";
				};

				max77802_ldo28_reg: LDO28 {
					regulator-name = "vcc_1.8v_mhl";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vcc_1.8v_mhl";
				};

				max77802_ldo29_reg: LDO29 {
					regulator-name = "tsp_vdd_1.8v";
					regulator-min-microvolt = <1800000>;
					regulator-max-microvolt = <1800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "tsp_vdd_1.8v";
				};

				max77802_ldo30_reg: LDO30 {
					regulator-name = "vmifs_1.0v_ap";
					regulator-min-microvolt = <1000000>;
					regulator-max-microvolt = <1000000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vmifs_1.0v_ap";
				};

				max77802_ldo32_reg: LDO32 {
					regulator-name = "irled_3.3V";
					regulator-min-microvolt = <3300000>;
					regulator-max-microvolt = <3300000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "irled_3.3V";
				};

				max77802_ldo33_reg: LDO33 {
					regulator-name = "vcc_2.8v_ap";
					regulator-min-microvolt = <2800000>;
					regulator-max-microvolt = <2800000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "vcc_2.8v_ap";
				};

				max77802_ldo35_reg: LDO35 {
					regulator-name = "cam_sensor_core_1.2v";
					regulator-min-microvolt = <1050000>;
					regulator-max-microvolt = <1200000>;
					regulator-always-on;
					regulator-boot-on;
					regulator-apply-uV;
					regulator-valid-modes-mask {	
						regulator-change-status;
					};
					regulator-state-mem {
						regulator-status-disabled;
						regulator-status-enabled;
					};
					max77802,consumer-supplies = "cam_sensor_core_1.2v";
				};
			};
		};
	};
};